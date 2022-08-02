#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
	// 입력 받기
	int N, M;
	vector<int> v;
	vector<int> se;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		v.emplace_back(tmp);
	}
	cin >> M;
	for (int i = 0; i < 2 * M; ++i) {
		int tmp;
		cin >> tmp;
		se.emplace_back(tmp);
	}

	set<pair<int, int>> pSet;
	for (int i = 0; i < 2 * M; i = i + 2) {
		int S = se[i] - 1;
		int E = se[i + 1] - 1;
		int s = S + (S - E / 2); // 홀수, 짝수 둘 다 같은 식을 사용
		int e = E - (S - E / 2); // 홀수, 짝수 둘 다 같은 식을 사용
		// 이진 탐색으로 가능한 곳 빠르게 찾기. 가능한 곳 부터 시작
		int jump = (s - S) / 2;
		int sumJump = 0;
		while (jump > 0) {
			if (pSet.count({ s - sumJump - jump, e + sumJump + jump }) == 1) {
				sumJump += jump;
			}
			jump = jump / 2;
		}
		s -= sumJump;
		e += sumJump;
		// cout << "jump: " << sumJump << endl;

		bool isP = true;
		while (S <= s && e <= E) {
			if (v[s] == v[e]) {
				pSet.insert({ s, e });
			}
			else {
				isP = false;
				break;
			}
			--s;
			++e;
		}
		if (isP) {
			cout << "1" << endl;
		}
		else {
			cout << "0" << endl;
		}
	}

	return 0;
}
