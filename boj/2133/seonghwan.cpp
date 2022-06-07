#include <iostream>

using namespace std;

int n;
int dp[31] = { 0, };

int main() {


	cin >> n;

	//홀수는 무조건 안됨
	if (n % 2 != 0) {
		cout << 0;
		return 0;
	}
	dp[0] = 1;	//이건 예외케이스 도형들 계산시 곱해줘야하므로 필요
	dp[2] = 3;

	for (int i = 4; i <= n; i = i + 2) {
		dp[i] = dp[i - 2] * 3;	//평범한 케이스
		for (int j = 0; j <= i - 4; j = j + 2) {
			dp[i] = dp[i] + dp[j] * 2;		//너비가 4 + 4 * x인 놈들과 6 + 4 * x인 놈들의 경우 계산
		}
	}

	cout << dp[n];

	return 0;
}
