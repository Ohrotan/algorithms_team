#include <iostream>
#include <cstring>
using namespace std;

int R, C, answer;
int map[50][50];
bool footprints[50][50];
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void calcNumOfLand(int y, int x) {
	footprints[y][x] = true;
	for (int dir = 0; dir < 8; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if ((ny < 0) || (ny > R - 1) || (nx < 0) || (nx > C - 1)) {
		    continue;
		}
		if ((map[ny][nx] == 1) && (!footprints[ny][nx])) {
			calcNumOfLand(ny, nx);
		}
	}
}

int main() {
    while (1) {
        cin >> C >> R;
        if ((R == 0) && (C == 0)) {
            break;
        }
        
        answer = 0;
        memset(map, 0, sizeof(map));
        memset(footprints, false, sizeof(map));
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> map[i][j];
            }
        }
        
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if ((map[i][j] == 1) && (!footprints[i][j])) {
			        calcNumOfLand(i, j);
			        answer++;
		        }
            }
        }
        
        cout << answer << "\n";
    }
    
    return 0;
}
