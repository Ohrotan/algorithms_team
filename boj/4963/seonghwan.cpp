#include<iostream>
#include<vector>

using namespace std;

int map[51][51] = { 0, };

void dfs(int i, int j) {
	if (map[i][j] == 1) {
		map[i][j] = 0;//검사한 섬은 전부 바다로 바꾸어준다.
	}
	else {
		return;
	}

	dfs(i + 1, j);
	dfs(i + 1, j + 1);
	dfs(i, j + 1);
	dfs(i - 1, j + 1);
	dfs(i - 1, j);
	dfs(i - 1, j - 1);
	dfs(i, j - 1);
	dfs(i + 1, j - 1);//시계방향으로 검사하여준다.

	return;
}



int main() {
	int w, h;
	int temp;
	int cnt = 0;


	do {
		scanf("%d %d", &w, &h);
		if (w != 0 && h != 0) {

			for (int i = 1; i <= h; i++) {
				for (int j = 1; j <= w; j++) {
					scanf("%d", &temp);
					map[i][j] = temp;
				}
			}//지도에 섬의 위치를 놓는다.

			for (int i = 1; i <= h; i++) {
				for (int j = 1; j <= w; j++) {
					if (map[i][j] == 1) {//섬을 찾으면 섬을 전부 0로 바꾸어준다.
						dfs(i, j);
						cnt++;
					}
				}
			}

			printf("%d\n", cnt);
			cnt = 0;

		}

	} while (w != 0 && h != 0);


	return 0;
}