#include <iostream>
#include <queue>

using namespace std;
#define MAX_W 50 + 2
#define MAX_H 50 + 2

int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

struct Loc {
    int y;
    int x;
};

int w, h;
int map[MAX_H][MAX_W];
int v[MAX_H][MAX_W];
queue<Loc> q;
int cnt = 0;

void bfs(int y, int x) {
    q.push({y, x});
    v[y][x] = cnt;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        int yy, xx;
        for (int i = 0; i < 8; i++) {
            yy = y + dy[i];
            xx = x + dx[i];
            if (yy < 0 || yy >= h || xx < 0 || xx >= w || v[yy][xx] != 0 || map[yy][xx] == 0) continue;
            q.push({yy, xx});
            v[yy][xx] = cnt;
        }
    }
}

int solve() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            v[i][j] = 0;
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (v[i][j] != 0 || map[i][j] == 0) continue;
            cnt++;
            bfs(i, j);
        }
    }
    return cnt;
}

int main(void) {
    while (true) {
        cin >> w >> h;
        cnt = 0;
        if (!w && !h) return 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }
        cout << solve() << '\n';
    }

    return 0;
}
