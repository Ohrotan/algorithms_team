#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int K;
int w[101];
int v[101];
int dp[101][100001];

int main(void){
    scanf("%d %d", &N, &K);
    for(int i = 1; i <= N; i++){
        scanf("%d %d", &w[i], &v[i]);
    }

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= K; j++){
            if (w[i] <= j)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    printf("%d\n", dp[N][K]);

    return 0;
}
