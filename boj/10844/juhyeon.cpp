#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int n;
long long dp[101][10];
long long mod = 1000000000;
// dp[자리수][마지막숫자]
int main()
{
    cin >> n;
    //init
    long long ans = 0; // 1자리수
    for (int i = 1; i < 10; i++)
    {
        dp[1][i] = 1;
    }
    //두자리 수부터 구하기
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0)
                dp[i][j] = dp[i - 1][1] % mod;
            else if (j == 9)
                dp[i][j] = dp[i - 1][8] % mod;
            else
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
        }
    }

    for (int j = 0; j < 10; j++)
    {
        ans = (ans + dp[n][j]) % mod;
    }
    cout << ans << endl;
    return 0;
}
