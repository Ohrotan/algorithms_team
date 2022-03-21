#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, W;

	cin >> N;
	cin >> W;
	vector<int> memo(W+1, 0);
	for (int i = 0; i < N; ++i) {
		int w;
		int v;
		cin >> w;
		cin >> v;
		vector<int> curMemo = memo;
		for (int j = 0; j <= W; ++j) {
			if (j + w <= W) {
				if (curMemo[j] + v > memo[j + w]) {
					memo[j + w] = curMemo[j] + v;
				}
			}
		}
	}
	cout << memo[W];
	
	return 0;
}
