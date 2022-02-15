// 완전 탐색도 시간은 충분
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int maxSheep = 1;

void dfs(vector<int>& info, vector<vector<int>>& graph, vector<int> lastNodes, int sheep, int wolf);

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    
    vector<vector<int>> graph(info.size());  // 노드->(노드들) 그래프
    vector<int> lastNodes;
    
    for (vector<int> edge : edges) {
        graph[edge[0]].push_back(edge[1]);
    }
    
    // 0번째 노드는 이미 선택되었음
    for (int nextNode : graph[0]) {
        lastNodes.push_back(nextNode);    
    }
    dfs(info, graph, lastNodes, 1, 0);
    
    answer = maxSheep;
    
    return answer;
}

void dfs(vector<int>& info, vector<vector<int>>& graph, vector<int> lastNodes, int sheep, int wolf) {
    if (maxSheep < sheep) maxSheep = sheep;
    for (int node : lastNodes) {
        if (info[node] == 0) {  // sheep
            // update lastNodes & dfs
            // lastNodes.erase(remove(lastNodes.begin(), lastNodes.end(), node), lastNodes.end());
            vector<int> nextLastNodes;
            for (int lastNode : lastNodes) {
                if (lastNode != node) {
                    nextLastNodes.push_back(lastNode);
                }
            }
            for (int nextNode : graph[node]) {
                nextLastNodes.push_back(nextNode);
            }
            dfs(info, graph, nextLastNodes, sheep+1, wolf);
        } else {  // wolf
            if (wolf+1 < sheep) {
                // update lastNodes & dfs
                vector<int> nextLastNodes;
                for (int lastNode : lastNodes) {
                    if (lastNode != node) {
                        nextLastNodes.push_back(lastNode);
                    }
                }
                for (int nextNode : graph[node]) {
                    nextLastNodes.push_back(nextNode);
                }
                dfs(info, graph, nextLastNodes, sheep, wolf+1);
            }
        }
    }
}
