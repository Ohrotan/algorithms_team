#include <iostream>

using namespace std;

int item[102][2] = {0, };	//물품들을 차례대로 저장
int valueAccumulation[102][100000] = {0, };	//{i, j}라고 쳤을 때, 0 ~ i번째 까지들의 아이템들로 j kg을 구성할 때 만들 수 있는 최대 가치를 저장

int main() {
	cin.tie();
	cout.tie();

	int N, K;

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> item[i][0] >> item[i][1];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			if (j < item[i][0]) {
				//현재 계산중인 무게가 현재 확인중인 물품의 무게보다 작다면 어차피 해당 물품은 계산중인 무게의 효용에 관여 못하므로
				//이전 물품까지의 효용을 그대로 현재 계산중인 무게의 효욜치에 더한다.
				valueAccumulation[i][j] = valueAccumulation[i - 1][j];
			}
			else {
				//현재 계산중인 무게가 현재 확인중인 물품의 무게보다 크다면, 현재 확인중인 물품의 가치 + 현재 확인중인 물품을 넣고도 남는 무게로 만들 수 있는 최대가치(valueAccumulation[i - 1][j - item[i][0]] + item[i][1])랑
				//직전 물품까지 검사했을 때 j kg으로 만들 수 있는 최대 가치랑 둘 중 더 큰 가치를 valueAccumulation에 대입(축적)
				if (valueAccumulation[i - 1][j] > valueAccumulation[i - 1][j - item[i][0]] + item[i][1]) {
					valueAccumulation[i][j] = valueAccumulation[i - 1][j];
				}
				else {
					valueAccumulation[i][j] = valueAccumulation[i - 1][j - item[i][0]] + item[i][1];
				}
			}
		}
	}

	cout << valueAccumulation[N][K];


}
