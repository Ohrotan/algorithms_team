// greedy 하게 앞사람부터 최대한 먹게 해준다.
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int N;
	int K;
	string table;

	cin >> N;
	cin >> K;
	cin >> table;
	// cout << N << " " << K << " " << table;

	vector<int> P;
	vector<int> H;
	int idxH = 0;
	int idxP = 0;
	int answer = 0;

	for (int i = 0; i < N; ++i) {
		if (table[i] == 'H') {
			H.push_back(i);
		}
		else {
			P.push_back(i);
		}
	}

	while(idxP < P.size() && idxH < H.size()) {
		// 사람 범위 안에 햄버거가 있는 경우 가능
		if ((P[idxP] - K <= H[idxH]) && (H[idxH] <= P[idxP] + K)) {

		}
		// 사람 범위 왼쪽에 햄버거가 있는 경우 사람 범위까지 햄버거를 끌어옴
		else if (P[idxP] - K > H[idxH]) {
			while (P[idxP] - K > H[idxH]) {
				++idxH;
				if (idxH >= H.size()) break;
			}
		}
		// 사람 범위 오른쪽에 햄버거가 있는 경우 햄버거까지 사람을 끌어옴
		else if (P[idxP] + K < H[idxH]) {
			while (P[idxP] + K < H[idxH]) {
				++idxP;
				if (idxP >= P.size()) break;
			}
		}
		// 섭취 후 다음으로 이동
		++answer;
		++idxP;
		++idxH;
	}
	cout << answer;

	return 0;
}
