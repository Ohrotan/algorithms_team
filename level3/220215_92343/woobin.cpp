#include <vector>
#include <cstring>
using namespace std;

bool visit[17]; // 방문 체크 배열
vector<int> nodes[17]; // edges를 탐색하기 쉽게 만든 nodes
int answer = 0;
vector<int> currentNodes; //

void dfs(vector<int> info, int lambs, int wolves) {
    if(wolves == lambs) {
        return;
    }
    
    answer = lambs > answer ? lambs : answer;
    
    // currentNodes의 크기가 반복문 도중 바뀔 수 있으므로 temp배열 생성
    vector<int> temp;
    temp.assign(currentNodes.begin(), currentNodes.end());
    
    for(auto&& e : temp) {
        for(auto&& next : nodes[e]) {
            // 인접노드의 방문 가능한 자식노드를 택함
            if(!visit[next]) {
                visit[next] = true;
                currentNodes.push_back(next);
                // lamb이면 offset = 1, wolves면 offset = 0
                int offset = (info.at(next) + 1) % 2;
                dfs(info, lambs + offset, wolves + info.at(next));
                currentNodes.pop_back();
                visit[next] = false;
            }
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    memset(visit, false, sizeof(visit));
    
    // 계산하기 쉽게 nodes 배열에 추가, 인접리스트를 담은 배열이라고 생각하면 됨
    for(auto&& e : edges) {
        nodes[e.at(0)].push_back(e.at(1));
        nodes[e.at(1)].push_back(e.at(0));
    }
    
    currentNodes.push_back(0);
    visit[0] = true;
    dfs(info, 1, 0);
    return answer;
}
