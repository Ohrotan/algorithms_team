#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;


priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;

bool cmp(vector<int> a, vector<int> b) {
  if (a[0] < b[0])
    return true;
  else if (a[0] == b[0]) {
    if (a[1] < b[1])
      return true;
    else
      return false;
  } else
    return false;
}
int solution(vector<vector<int>> jobs) {
  int answer = 0;
  sort(jobs.begin(), jobs.end());
  // for (int i = 0; i < jobs.size(); i++) {
  //   cout << jobs[i][0] << " " << jobs[i][1] << "\n";
  // }
  int sz = jobs.size();
  int time = 0;
    int j=0;
   while (j < jobs.size() || !pq.empty()) {
        //들어올 대기열이 남아있고, 들어올 대기열이 현재시간보다 작다면
        if (jobs.size() > j && time >= jobs[j][0]) {
            //우선순위 큐에 추가
            pq.push({jobs[j][1], jobs[j][0]});
            j++;
            //인덱스 증가
            //같은시간대에 다른작업이 더들어왔을 수 있으므로 다시 확인
            continue;
        }
        //큐가 비어있지 않다면
        if (!pq.empty()) {
            //시간에 이작업이 끝날때까지 걸리는 시간만큼 추가
            time += pq.top().first;
            //작업시간에 대기 시간만큼 추가(현재시간 - 들어온 시간)
            answer += time - pq.top().second;
            //작업이 끝났으므로 우선순위 큐에서 제거
            pq.pop();
        }
        else //큐가 비어있다면 다음작업 시간으로 넘김
            time = jobs[j][0];
    }
  return answer/sz;
}