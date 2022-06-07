// 경우의 수 3x2단독은 3개가 끝
// 3x4단독 2개, 3x6단독 2개, 3x짝수단독 2개

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;

	cin >> N;
	vector<int> memo(N+1, 0);

	if (N % 2 == 1) {  // N이 홀수면 성립x
		cout << 0;
		return 0;
	}

	memo[0] = 1;
	memo[2] = 3;

	for (int i = 4; i <= N; i += 2) {
		int next = memo[i-2] * 3;
		for (int j = i - 4; j >= 0; j -= 2) {
			next += memo[j] * 2;
		}
		memo[i] = next;
	}
	cout << memo[N];
	
	return 0;
}
