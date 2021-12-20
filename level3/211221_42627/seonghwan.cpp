/*
    1. 시간 : 0.01ms~0.38ms
    2. 메모리 : 4.33MB
    <풀이 방법>
    task가 처리되는 시간이 가작 작은게 먼저 처리 되어야함(그래야 뒤에 기다리는 애들의 대기시간 평균이 최소가 됨)
    =>우선순위 큐 사용
    1. 현재 시간과 최근에 들어온 task 사이에 있는 task들을 전부 queue에 삽입.
    2. queue가 빌 때 까지 작업을 처리 한 후 task가 들어온 시간과 현재 시간으로 총 걸린 시간 answer에 추가(나중에 나눌꺼임)
    3. queue에 있는 작업들 전부 처리한 후 현재시간 update 후 다시 update된 현재시간과 이전에 들어온 task사이에 있는 task들을 전부 queue에 삽입(1번 내용)
    4. task가 전부다 queue에 들어올 떄 까지 반복 후 다시 queue가 빌 때 까지 task 처리 반복
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void ProcessRemainTask();
void ProcessAllTask();

// 동일 시간대에 들어온 task들 중 작업시간이 짧은 애들이 앞에 와야 하므로 연산자 오버로딩으로 작은게 우선순위로
struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};

priority_queue<vector<int>, vector<vector<int>>, cmp> diskQueue;//처리할 작업을 넣는 우선순위큐(top이 젤 작음)
vector<vector<int>> jobs;
int answer = 0;
int processignTime = 0;   // 현재 프로세스가 처리되고있는 시간
int i = 0;

int solution(vector<vector<int>> jobsTemp) {
    sort(jobsTemp.begin(), jobsTemp.end()); // 작업이 요청되는 시점이 빠른 순으로 정렬
    jobs = jobsTemp;

    ProcessAllTask();//모든 task를 diskQueue에 넣어 테스트한다.
    answer = (int)(answer / jobs.size());

    return answer;  // 평균 시간 반환
}

void ProcessAllTask() {
    while (i < jobs.size()) {//task들을 다 넣기 전까지 반복
        if (jobs[i][0] <= processignTime) {// 현재 시간보다 이전에 들어온 task들은 전부 우선순위큐에 삽입
            diskQueue.push(jobs[i]);
            i++;
            continue;
        }
        ProcessRemainTask();//우선순위 큐에 있는 애들 다 처리함
    }
    while (!diskQueue.empty())
        ProcessRemainTask();//마지막 task까지 넣은 후 우선순위큐에 남아있는 task 처리함
}

void ProcessRemainTask() {
    if (!diskQueue.empty()) {// 우선순위큐에 처리해야 할 task가 남아있을 때
        processignTime += diskQueue.top()[1];//현재 작업이 처리가 끝나면 현재시각을 작업이 끝나는 시간으로 변경
        answer += (processignTime - diskQueue.top()[0]);//걸린시간 추가해주기
        diskQueue.pop();
    }
    else processignTime = jobs[i][0];// task 수행할 작업이 없는 경우 다음 작업이 들어오는 시간으로 현재시간 변경  
}
