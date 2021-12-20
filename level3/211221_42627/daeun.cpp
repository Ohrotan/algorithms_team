#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

struct JOB{
    int t_start; // 작업 요청 시점
    int t_exe; // 작업 소요 시간
};

// 작업 소요 시간 기준의 최소 힙
struct cmp{
    bool operator()(JOB a, JOB b){
        return a.t_exe > b.t_exe;
    }
};

int solution(vector<vector<int>> jobs) {
    // for(int i = 0; i < jobs.size(); i++){
    //     printf("[%d, %d] \n", jobs[i][0], jobs[i][1]);
    // }
    //jobs 2차원 배열 오름 차순 정렬
    sort(jobs.begin(), jobs.end());
    // for(int i = 0; i < jobs.size(); i++){
    //     printf("[%d, %d] \n", jobs[i][0], jobs[i][1]);
    // }

    //최소 힙 pQ : 현재시점(time) 이전에 요청된 작업들을 담고 있음 (작업 소요 시간 기준 최소 힙)
    priority_queue<JOB, vector<JOB>, cmp> pQ;
    int job_idx = 0;
    int time;
    int sum_time = 0;
    pQ.push({jobs[0][0], jobs[0][1]});
    job_idx++;
    time = jobs[0][0];

    while(!pQ.empty()){
        //가장 작업 소요 시간이 짧은 job을 pop
        JOB job = pQ.top();
        // sum_time += (time - job.t_start) + job.t_exe;
        // job의 총 요청~종료 시간을 구함
        int wait = time - job.t_start;
        if(wait > 0){
            sum_time += wait + job.t_exe;
        }
        else{
            sum_time += job.t_exe;
        }
        // 현재시점(time)을 재설정
        time += job.t_exe;
        pQ.pop();
        // printf("time: %d, exetime: %d\n", time, job.t_exe);

        // 현재시점(time) 기준 이전 job들을 최소 힙에 삽입
        // 최소힙 비었는데, 아직 남은 job이 있다면 다음 1개 job을 최소 힙에 삽입
        for(int i = job_idx; i < jobs.size(); i++){   
            if(jobs[i][0] <= time){
                JOB job = {jobs[i][0], jobs[i][1]};
                pQ.push(job);
                job_idx++;
            }
            if(pQ.size() == 0 && job_idx < jobs.size()){
                JOB job = {jobs[i][0], jobs[i][1]};
                pQ.push(job);
                job_idx++;
                break;
            }
        }
    }

    int answer = sum_time / jobs.size();
    return answer;
}
