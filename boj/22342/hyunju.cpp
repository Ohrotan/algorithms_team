#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int M;
	int N;
	vector<string> table;

	cin >> M;
	cin >> N;

	for (int i = 0; i < M; ++i) {
		string s = "";
		cin >> s;
		table.push_back(s);
	}

	// N == 1 일 때 예외 처리
	if (N == 1) {
		cout << "0";
		return 0;
	}

	// 0열 초기값 배열 생성
	vector<int> cur(M, 0);
	vector<int> nxt(M, 0);
	for (int i = 0; i < M; ++i) {
		cur[i] = table[i][0] - '0';
	}

	// 열단위로 앞으로 나가면서 값 계산
	for (int i = 1; i <= N-2; ++i) {
		nxt[0] = max(cur[0], cur[1]) + (table[0][i] - '0');
		for (int j = 1; j <= M - 2; ++j) {
			nxt[j] = max(max(cur[j - 1], cur[j]), cur[j + 1]) + (table[j][i] - '0');
		}
		nxt[M - 1] = max(cur[M - 2], cur[M - 1]) + (table[M - 1][i] - '0');
		cur.swap(nxt);  // 아래 코드와 시간 복잡도는 같다.  (아마도 컴파일러에서 알아서 얕은 복사를 할 것 같다.
		// cur = nxt;  
	}

	// 마지막 열의 최대값 계산
	int maxNum = 0;
	for (int i = 0; i < M; ++i) {
		if (maxNum < cur[i]) maxNum = cur[i];
	}
	cout << maxNum;

	return 0;
}
