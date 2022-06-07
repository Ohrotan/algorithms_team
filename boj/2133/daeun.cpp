#include <iostream>
#include <stdio.h>

using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);
    if (n%2 == 1) {
        printf("0\n");
        return 0;
    }

    int dp[31] = { 0, };

    dp[0] = 1;
    dp[2] = 3;

    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 2] * 3; 
        for (int j = 4; j <= i; j += 2) {
            dp[i] += dp[i - j] * 2;
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}
