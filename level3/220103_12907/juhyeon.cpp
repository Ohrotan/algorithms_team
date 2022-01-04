#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    int dp[100001];

    dp[0] = 1;
    for (int i = money[0]; i <= n; i += money[0])
    {
        dp[i] = 1;
    }

    for (int i = 1; i < money.size(); i++) // 현재 금액
    {
        for (int j = money[i]; j <= n; j++)
        {
            dp[j] += dp[j - money[i]] % 1000000007;
        }
    }
    answer = dp[n];
    return answer;
}