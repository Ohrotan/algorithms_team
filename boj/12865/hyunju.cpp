#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, W;

	cin >> N;
	cin >> W;
	vector<int> memo(W+1, 0);	//이전 아이템까지 조사했을 때, w무게에서 가질 수 있는 최대 가치를 memo.at(w)로 정의
	for (int i = 0; i < N; ++i) {
		int w;
		int v;
		cin >> w;
		cin >> v;
		vector<int> curMemo = memo;	//현재 조사중인 아이템의 w무게에서 가질 수 있는 최대 가치를 curMemo.at(w)
		for (int j = 0; j <= W; ++j) {
			if (j + w <= W) {	//현재 최대가치를 조사중인 무게와 현재 조사중인 아이템의 무게 합이 넘어가면 어차피 못담으므로 이전 가치를 그대로 둠
				if (curMemo[j] + v > memo[j + w]) {
					memo[j + w] = curMemo[j] + v;
				}
			}
		}
	}
	cout << memo[W];
	
	return 0;
}
