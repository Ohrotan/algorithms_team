// (9.07ms, 5.13MB)
#include <vector>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = 0;
    
    vector<vector<int>> road(n+1, vector<int>());

    for(int i = 0; i < edge_list.size(); i++){
        road[edge_list[i][0]].push_back(edge_list[i][1]);
        road[edge_list[i][1]].push_back(edge_list[i][0]);
    }
             
    vector<vector<int>> dp(k, vector<int>(n+1, 2147000000 - gps_log.size()));
    
    dp[0][gps_log[0]] = 0; // 최초 위치의 수정값 = 0
    for(int t = 1; t < k; t++){
        for (int i = 1; i <= n; i++){
            int add = (gps_log[t] == i) ? 0 : 1;
            dp[t][i] = min(dp[t][i], dp[t-1][i]+add);
            // dp[t][i] = t 시간에 i node로 올 수 있는 최소값, t-1 시간에 i node로 올 수 있는 최소값 + 고친 횟수 중 작은 값
            for (int l = 0; l < road[i].size(); l++){
                dp[t][i] = min(dp[t][i], dp[t-1][road[i][l]]+add);
            }
        }
    }
    
    if(dp[k-1][gps_log.back()] == 2147000000 - gps_log.size())
        answer = -1; // 수정 불가
    else
        answer = dp[k-1][gps_log.back()]; // 경로를 최소로 수정한 값
    return answer;
}
