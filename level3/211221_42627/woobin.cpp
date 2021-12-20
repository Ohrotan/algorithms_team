#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Request {
    int begin;
    int time;
};

bool operator<(Request a, Request b) {
        return a.time > b.time;
}

bool compare(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int now = 0;
    int idx = 0;
    
    std::sort(jobs.begin(), jobs.end(), compare);
    priority_queue<Request> hardDisk;

    while(idx < jobs.size() || !hardDisk.empty()) {
        if(idx < jobs.size() && jobs[idx].at(0) <= now) {
            hardDisk.push({jobs[idx].at(0), jobs[idx].at(1)});
            idx++;
        } else {
            if(!hardDisk.empty()) {
                Request request = hardDisk.top();
                hardDisk.pop();
                now += request.time;
                answer += (now - request.begin);
            } else {
                now = jobs[idx].at(0);
            }
        }
    }
    
    return answer / jobs.size();
}
