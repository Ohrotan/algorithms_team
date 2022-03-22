#include <iostream>

int N, K;
int weight[101], value[101];
int dp[101][100001];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> N >> K;
	for (int i = 1; i <= N; i++) {
        std::cin >> weight[i] >> value[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			dp[i][j] = dp[i - 1][j];
			if(j - weight[i] >= 0) {
                dp[i][j] = dp[i][j] > (dp[i - 1][j - weight[i]] + value[i]) ? dp[i][j] : (dp[i - 1][j - weight[i]] + value[i]);
			}
		}
	}

    std::cout << dp[N][K] << "\n";
	return 0;
}
