#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

/*
	통과 (246.06ms, 4.32MB)
*/
int r, c;
char M[120][120];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
typedef struct info
{
    int x, y, dir, cnt;
} info;

bool solve(int x, int y)
{
    queue<info> q;
    q.push({x, y, -1, 0});
    char target = M[x][y];
    while (!q.empty())
    {
        int nx = q.front().x;
        int ny = q.front().y;
        int dir = q.front().dir;
        int cnt = q.front().cnt;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            //역방향 처리, -1은 초기이란 뜻으로, 방향이 상관없다는 의미
            if (dir != -1 && abs(dir - i) == 2)
                continue;
            int tx = nx + dx[i];
            int ty = ny + dy[i];
            int tcnt = cnt;
            //방향이 다르다면 꺾기
            if (dir != -1 && dir != i)
                tcnt += 1;
            if (tx < 0 || tx >= r || ty < 0 || ty >= c || tcnt > 1)
                continue;
            if (M[tx][ty] == '*')
                continue;
            //계속 탐색을 위해 push
            else if (M[tx][ty] == '.')
            {
                q.push({tx, ty, i, tcnt});
            }
            else
            {
                if (M[tx][ty] == target)
                {
                    M[x][y] = '.';
                    M[tx][ty] = '.';
                    return true;
                }
            }
        }
    }
    return false;
}

string solution(int m, int n, vector<string> board)
{
    string answer = "";
    r = m;
    c = n;
    map<char, int> alphabet;
    vector<pair<char, pair<int, int> >> data;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            M[i][j] = board[i][j];
            if (M[i][j] >= 'A' && M[i][j] <= 'Z' &&alphabet[M[i][j]] == 0)
            {
                data.push_back({M[i][j], {i, j}});
                alphabet[M[i][j]] = 1;
            }
        }
    }
    //순서대로 처리하기 위해 정리
    sort(data.begin(), data.end());
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (int i = 0; i < data.size(); i++)
        {
            char tchar = data[i].first;
            pair<int, int> tpair = data[i].second;
            flag = solve(tpair.first, tpair.second);
            if (flag)
            {
                answer += tchar;
                data.erase(data.begin() + i);
                break;
            }
        }
    }
    if (data.size() != 0)
        answer = "IMPOSSIBLE";

    return answer;
}