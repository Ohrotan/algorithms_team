// 평균 시간: 0.1265ms, 평균 메모리: 4.178MB 
// 제일 소요 시간이 짧은 작업부터 처리. 비선점
// 풀이 설명: 
// 기준 시간안에 있는 작업들을 모두 우선순위 큐에 넣어 작업을 수행하도록 하고,
// 우선순위 큐에서 뺀 시간만큼 기준 시간을 다시 더해주고 이를 반복한다.
// 남은 모든 작업들의 요청 시간이 기준 시간 바깥에 있다면 기준 시간을 다음 작업 요청 시간으로 이동시킨다.
// 반복 중에 각 작업 수행 완료 시간의 합을 구한다.
// 정답은 (각 작업 수행이 끝난 시간의 총 합) - (각 작업이 들어온 시간의 총 합) 의 평균
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    int jobLen = jobs.size();  // jobLen: 전체 작업 수
    int sum_request = 0;  // sum_request: 각 작업이 들어온 시간의 총 합
    int sum_response = 0;  // sum_response: 각 작업 수행이 끝난 시간의 총 합
    priority_queue<int, vector<int>, greater<int>> pq;  // pq: 짧은 수행 시간이 우선인 우선순위 큐
    
    // 작업이 들어온 시간 순으로 jobs 정렬
    sort(jobs.begin(), jobs.end(), [](vector<int> a, vector<int> b) {return a[0] < b[0];});
    
    int time = jobs[0][0];  // time: 기준이 되는 시간
    int jobIdx = 0;  // jobIdx: 현재 push할 job의 index
    while (!(jobIdx == jobLen && pq.size() == 0)) {
        
        // 기준 시간까지 들어온 작업들을 pq에 넣음
        while (jobIdx < jobLen) {
            if (jobs[jobIdx][0] <= time) {
                pq.push(jobs[jobIdx][1]);
                sum_request += jobs[jobIdx][0];
                ++jobIdx;
            } else {
                break;
            }
        }
        
        // pq에서 가장 짧은 수행 시간을 가진 작업을 완료시키고 수행 시간만큼 기준 시간을 더함
        int processTime = pq.top();
        pq.pop();
        time += processTime;  
        sum_response += time;  // 작업 완료 시간 추가
        
        // 만약 기준 시간에 수행할 작업이 들어와 있지 않다면 그 작업이 수행하는 time으로 이동
        if (jobIdx < jobLen && pq.size() == 0 && jobs[jobIdx][0] > time) {
            time = jobs[jobIdx][0];
        }
    }
    
    // 정답은 (각 작업 수행이 끝난 시간의 총 합) - (각 작업이 들어온 시간의 총 합) 의 평균
    answer = (sum_response - sum_request) / jobLen;    
    
    return answer;
}
