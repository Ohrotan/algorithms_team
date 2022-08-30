#include<iostream>
#include<vector>

using namespace std;

int map[51][51] = { 0, };

void dfs(int i, int j) {
	if (map[i][j] == 1) {
		map[i][j] = 0;//�˻��� ���� ���� �ٴٷ� �ٲپ��ش�.
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
	dfs(i + 1, j - 1);//�ð�������� �˻��Ͽ��ش�.

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
			}//������ ���� ��ġ�� ���´�.

			for (int i = 1; i <= h; i++) {
				for (int j = 1; j <= w; j++) {
					if (map[i][j] == 1) {//���� ã���� ���� ���� 0�� �ٲپ��ش�.
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