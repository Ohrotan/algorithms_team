#include <vector>
#include <algorithm>

using namespace std;

int maximumNumber = 40000;

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    
    vector<vector<int>> linkedNodes(n + 1, vector<int>());
    
    for (int i = 0; i < m ; ++i) 
    {
        int node1 = edge_list[i][0];
        int node2 = edge_list[i][1];
        
        linkedNodes[node1].push_back(node2);
        linkedNodes[node2].push_back(node1);
    } 
    
    vector<vector<int>> DP(k, vector<int>(n + 1, maximumNumber)); 
    
    DP[0][gps_log[0]] = 0;
    
    for (int i = 1; i < k; ++i) {
        for (int j = 1; j <= n; ++j) {
            DP[i][j] = min(DP[i - 1][j], DP[i][j]);
            
            for (int nodeTemp : linkedNodes[j]) 
            { 
                DP[i][j] = min(DP[i - 1][nodeTemp], DP[i][j]);
            }
            
            if(gps_log[i] != j)
                DP[i][j] += 1;
        } 
    }
    
    if (DP[k - 1][gps_log[k - 1]] >= maximumNumber) 
    { 
        return -1; 
    }
    return DP[k - 1][gps_log[k - 1]];
}
