#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int N;
	int d;
	int k;
	int c;
	bool isNewC = true;
	vector<int> table;

	cin >> N;
	cin >> d;
	cin >> k;
	cin >> c;

	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		table.push_back(tmp);
		// 쿠폰 번호가 존재하는지 확인
		if (tmp == c) {
			isNewC = false;
		}
	}

	// 범위에 있는 초밥 종류 당 중복 개수를 확인하는 배열
	vector<int> cnt(d + 1, 0);
	// 범위에 있는 서로 다른 초밥 종류 개수
	int kind = 0;
	int maxKind = 0;
	// 범위에 접시 k개 만큼 넣은 배열을 초기화
	for (int i = 0; i < k; ++i) {
		if (cnt[table[i]] == 0) {
			++kind;
		}
		cnt[table[i]] = cnt[table[i]] + 1;
	}
	// maxKind = kind;
	// 범위 시작, 끝
	int start = 0;
	int end = k - 1;
	// 범위를 1칸씩 이동
	end = (end + 1) % N;
	do {
		// 초밥 종류 개수 계산
		if (cnt[table[end]] == 0) {
			++kind;
		}
		cnt[table[end]] = cnt[table[end]] + 1;
		if (cnt[table[start]] == 1) {
			--kind;
		}
		cnt[table[start]] = cnt[table[start]] - 1;

		// 쿠폰 처리
		int plusKind = kind;
		if (isNewC) { // 새 쿠폰인 경우 무조건 +1
			++plusKind;
		}
		else { // 쿠폰 번호가 일치하면서 범위에 없는 초밥 종류인 경우 +1
			if ((cnt[table[(start) % N]] == 0 && table[(start) % N] == c) ||
				(cnt[table[(end + 1) % N]] == 0 && table[(end + 1) % N] == c)) {
				++plusKind;
			}
		}
		if (maxKind < plusKind) maxKind = plusKind;

		// cout << "s:" << start << " e:" << end << " k:" << plusKind << endl;

		start = (start + 1) % N;
		end = (end + 1) % N;
	} while (end != (k % N));

	cout << maxKind;

	return 0;
}
