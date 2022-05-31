#include <iostream>
#define MOD 1000000000
using namespace std;

int N;
long long answer;
long long dp[100][10];

// dfs로 안풀려서 다시 품
int main() {
    cin >> N;
    
    dp[0][0] = 0;
    for (int i = 1; i < 10; i++) {
        dp[0][i] = 1; 
    }
    
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j + 1];
            } else if (j == 9) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
            }
        }
    }
    
    for (int j = 0; j < 10; j++) {
        answer += (dp[N - 1][j] % MOD);
    }

    cout << answer % MOD << "\n";
}
