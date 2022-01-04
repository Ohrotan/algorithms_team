#include <vector>
#include <algorithm>
#define DIVI 1000000007

using namespace std;

int solution(int n, vector<int> money) {
    int dp[100001] = {0, };
    dp[0] = 1;

    std::sort(money.begin(), money.end());
    for(auto e : money) {
        for(int idx = 1; idx <= n; idx++) {
            if (idx - e < 0) {
                continue;
            }
            dp[idx] = (dp[idx] + dp[idx - e]) % DIVI;
        }
    }

    return dp[n] % DIVI;
}

