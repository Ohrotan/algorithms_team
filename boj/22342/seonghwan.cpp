#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> plusMap;
int savedMap[2001][2001] = { 0, };
int n, m;
int answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio();

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		plusMap.push_back(temp);
	}


	for (int j = 1; j < m; j++) {
		for (int i = 0; i < n; i++) {

			//가중치를 더해서 왼쪽 세 개 중 어느게 제일 큰지 비교
			int nextNumber = savedMap[i][j - 1] + (int)(plusMap[i][j - 1] - '0');
			if (i >= 1) {
				nextNumber = max(savedMap[i - 1][j - 1] + (int)(plusMap[i - 1][j - 1] - '0'), nextNumber);
			}

			if (i < n - 1) {
				nextNumber = max(savedMap[i + 1][j - 1] + (int)(plusMap[i + 1][j - 1] - '0'), nextNumber);
			}
			savedMap[i][j] = nextNumber;
		}
	}

	//맨 오른쪽께 제일 클 것이므로 그것들만 비교
	for (int i = 0; i < n; i++) {
		if (savedMap[i][m - 1] > answer) {
			answer = savedMap[i][m - 1];
		}
	}

	cout << answer;

	return 0;
}