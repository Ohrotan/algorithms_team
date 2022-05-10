#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
int d[120][210];
vector<int> adj[210];
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    memset(d,0,sizeof(d));
    for(int i=0;i<n;i++) adj[i].clear();
    for(int i=0;i<m;i++){
        adj[edge_list[i][0]-1].push_back(edge_list[i][1]-1);
        adj[edge_list[i][1]-1].push_back(edge_list[i][0]-1);
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            d[i][j] = 987654321;
        }
    }
    d[0][gps_log[0]-1] = 0;
    for(int i=0;i<(k-1);i++){
        for(int j=0;j<n;j++){
            for(int l=0;l<adj[j].size();l++){
                int next = adj[j][l];
                d[i+1][next] = min(d[i+1][next],d[i][j]+1);
                if(next==(gps_log[i+1]-1)) d[i+1][next] = min(d[i+1][next],d[i][j]);
            }
        }
    }
    int answer = d[k-1][gps_log[k-1]-1];
    if(answer>=987654321) return -1;
    else return answer;
}
