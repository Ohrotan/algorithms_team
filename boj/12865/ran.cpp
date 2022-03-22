#include <iostream>
using namespace std;
int N, K, item[102][2], dp[102][100003];

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 1; i < N + 1; i++) {
        scanf("%d %d", &item[i][0], &item[i][1]);
    }

    for (int i = 1; i < N + 1; i++) {
        int weight = item[i][0];
        int value = item[i][1];
        for (int j = 0; j <= K; j++) {
            if (j < item[i][0]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + value);
        }
    }
    printf("%d", dp[N][K]);
}
