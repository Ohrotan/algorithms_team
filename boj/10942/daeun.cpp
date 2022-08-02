#include <iostream>

using namespace std;
#define MAX_N 2000 + 2

int N, M;
int arr[MAX_N];
int dp[MAX_N][MAX_N];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        dp[i][i] = 1;
    }
    cin >> M;

    for (int i = 1; i <= N-1; i++) {
        if (arr[i] == arr[i+1]) dp[i][i+1] = 1;
    }

    for (int i = 2; i <= N - 1; i++) {
        for (int j = 1; j <= N - i; j++) {
            if (arr[j] == arr[j+i] && dp[j+1][j+i-1]) {
                dp[j][j+i] = 1;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        int S, E;
        cin >> S >> E;
        printf("%d\n", dp[S][E]);
    }

    return 0;
}
