#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

int maxSheepcnt = 0;
vector<vector<int>> graphs(20);

void dfs(int sheepcnt, int wolfcnt, int curNode, vector<int> nextNodes, vector<int> info){
    if(info[curNode] == 0){
        sheepcnt++;
    }
    else{
        wolfcnt++;
    }
    
    maxSheepcnt = max(maxSheepcnt, sheepcnt);
    
    if (sheepcnt <= wolfcnt)
        return;
    
    vector<int> tmp;
    for (int i = 0; i < nextNodes.size(); i++){
        tmp.push_back(nextNodes[i]);
    }
    
    nextNodes.erase(nextNodes.begin() + curNode);
    // printf("%d \n", graphs[curNode][1]);
    for (int i = 0; i < graphs[curNode].size(); i++){
        tmp.push_back(graphs[curNode][i]);
    }
        
    for (int i = 0 ; i < tmp.size(); i++){
        dfs(sheepcnt, wolfcnt, tmp[i], tmp, info);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    
    vector<int> nextNodes;
    
    for (int i = 0; i < edges.size(); i++){
        graphs[edges[i][0]].push_back(edges[i][1]);
        graphs[edges[i][1]].push_back(edges[i][0]);
    }
    
    nextNodes.push_back(0);
    dfs(0, 0, 0, nextNodes, info);
    return answer;
}
