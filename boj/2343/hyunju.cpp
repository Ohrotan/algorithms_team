#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// 입력 받기
	int N;
	int M;

	cin >> N;
	cin >> M;

	vector<int> v(N+1, 0);  // index까지의 합을 저장 (1~N) (굳이 필요는 없는 듯)

	// 입력 받고 초기화
	int tmp = 0;
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		v[i + 1] = v[i] + tmp;
	}

	// 이분 탐색
	int minBluelay = v[N];  // 가능한 블루레이 최대 크기
	int maxBluelay = 0;  // 불가능한 블루레이 최소 크기
	int bluelay = 50000;  // 현재 블루레이 크기
	while (true) {
		int bef = 0;
		int cur = 0;
		for (int bluelayCount = 0; bluelayCount < M; ++bluelayCount) {
			for (cur = bef+1; cur <= N; ++cur) {
				if (v[cur] - v[bef] <= bluelay) {
					// 블루레이 크기 안에 담을 수 있으면 다음 index로
				}
				else {
					// 블루레이 크기 안에 못 담음 
					bef = cur - 1;  // 이 전까지만 담고 다음 블루레이에 채워줄 준비
					break;
				}
			}
			if (cur == N + 1) break;
		}
		if (cur == N + 1) {
			// 가능, 블루레이 크기 줄이기
			minBluelay = bluelay;
		}
		else {
			// 불가능, 블루레이 크기 늘리기
			maxBluelay = bluelay;
		}
		bluelay = (minBluelay + maxBluelay) / 2;
		if (minBluelay - maxBluelay <= 1) {  // 블루레이 크기가 결정된다면 출력
			cout << minBluelay;
			break;
		}
	}

	return 0;
}
