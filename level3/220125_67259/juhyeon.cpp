#include <string>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int M[26][26];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

typedef struct Road
{
    int r;
    int c;
    int dir;
    int cost;
    int cnt;
};

int solution(vector<vector<int> > board)
{
    int ans=2e9;
    int N = board.size();
    queue<Road> q;
    vector<vector<int> > Cost(N, vector<int>(N, 2e9));
    q.push({0, 0, -1, 0,0});
    Cost[0][0] = 0;
    while (!q.empty())
    {
        int x = q.front().r;
        int y = q.front().c;
        int dir = q.front().dir;
        int cost = q.front().cost;
        int cnt = q.front().cnt;
        q.pop();

        //도착지점일 경우
        if (x == N - 1 && y == N - 1)
        {
            ans = min(ans, Cost[x][y]);
            continue;
        }
        for (int i = 0; i < 4; i++)
        {
            int tcost = cost;
            int tcnt = cnt;
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx > N - 1 || ty > N - 1 || tx < 0 || ty < 0)
                continue;
            if (board[tx][ty] == 1)
                continue;

            //방향 , -1이면 처음, dir ==i면 직선 도로
            if (dir == -1 || dir == i) tcost +=100;
            else tcost+=600;

            if(Cost[tx][ty] >= tcost){
                Cost[tx][ty] = tcost;
                q.push({tx,ty,i,tcost,cnt});
            }
            else if(cnt <=1){
                tcnt +=1;
                q.push({tx,ty,i,tcost,tcnt});
            }
        }
    }
    return ans;
}