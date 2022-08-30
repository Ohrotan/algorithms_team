#include <iostream>
#include <queue>

using namespace std;

int visit[51][51];
int map[51][51];
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int w, h;
void dfs(int x, int y)
{
    for (int i = 0; i < 9; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= h || ny < 0 || ny >= w)
            continue;
        if (visit[nx][ny] || !map[nx][ny])
            continue;
        visit[nx][ny] = 1;
        dfs(nx, ny);
    }
}
int main()
{
    while (true)
    {
        int cnt = 0;
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> map[i][j];
                visit[i][j] = 0;
            }
        }
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (!visit[i][j] && map[i][j])
                {
                    visit[i][j] = 1;
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}