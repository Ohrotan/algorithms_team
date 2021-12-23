#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs) {
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int jobCnt = jobs.size();
    int total = 0;
    int now = 0;
    
    // 초기값 설정, jobs를 요청순서 순으로 정렬
    std::sort(jobs.begin(), jobs.end(), [](vector<int> a, vector<int> b){
        return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
    });
    
    while (true) {
        int i = 0;
        for (; i < jobs.size(); ++i) {
            if (now >= jobs[i][0]) {
                pq.push({jobs[i][1], jobs[i][0]}); //소요시간, 요청시간
            } else {
                break;
            }
        }
        jobs.erase(jobs.begin(), jobs.begin() + i);
        // 공백 생기면
        if (pq.size() == 0) { 
            if (jobs.size() == 0) return total/jobCnt;
            now = jobs[0][0] + jobs[0][1];
            total += jobs[0][1];
            jobs.erase(jobs.begin(), jobs.begin()+1);
        } else { 
            now += pq.top().first;
            total += now - pq.top().second;
            pq.pop();
        }
    }
}
