#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = 0;
    vector<vector<int>> routes(n + 1);
    vector<vector<int>> dp(k, vector<int>(n + 1, INF)); 
     
    for (auto&& e : edge_list) {
        int start = e.at(0);
        int end = e.at(1);
        routes.at(start).push_back(end);
        routes.at(end).push_back(start);
    }
    
    dp[0][gps_log[0]] = 0; 
    for (int t = 1; t < k; t++) {
        for (int x = 1; x <= n; x++) {
            int minValue = dp[t - 1][x]; 

            for (int i = 0; i < routes[x].size(); i++) {
                minValue = min(dp[t - 1][routes[x][i]], minValue);    
            }
            
            dp[t][x] = (gps_log[t] != x) ? minValue + 1 : minValue;
        }
    }
    
    answer = dp[k - 1][gps_log[k - 1]];
    answer = (answer < INF) ? answer : -1;
    return answer;
}
