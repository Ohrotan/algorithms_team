#include <vector>
#include <queue>

#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3

using namespace std;

int N;
int dirs[4] = {UP,DOWN,LEFT,RIGHT};
vector<vector<int>> board;
vector<vector<vector<int>>> minCost; // [r][c][up,left,down,right] 별 최소 금액

struct Road {
    int r;
    int c;
    int dir;
    int cost;
    
    bool valid() {
        if (r < 0 || c < 0 || r >= N || c >= N) { return false; }
        if (board[r][c] == 1) { return false; }        
        return true;
    }
    bool build(int nextDir) {
        if      (nextDir == UP)    { r--; }
        else if (nextDir == DOWN)  { r++; } 
        else if (nextDir == LEFT)  { c--; }
        else if (nextDir == RIGHT) { c++; }
        
        if (valid() == false) { return false; }

        if (nextDir == dir) {
            cost += 100;
        } else {
            cost += 100 + 500;
        }
        dir = nextDir;
        return true;
    }
    int getMinCost() {
        return minCost[r][c][dir];
    }
    void setMinCost() {
        minCost[r][c][dir] = cost;
    }
};

queue<Road> q;

int abs(int a) { return a > 0? a : -a; }

void initMinCost() {
    for (int i = 0; i < N; ++i) {
        vector<vector<int>> tmp;
        for (int j = 0; j < N; ++j) {
            vector<int> tmp2;
            tmp2.assign(4,987654321);
            tmp.emplace_back(tmp2);
        }
        minCost.emplace_back(tmp);
    }
}

int solution(vector<vector<int>> _board) {
    int res = 987654321;
    N = _board.size();
    board = _board;
    initMinCost();

    q.push({0,0,DOWN,0});
    q.push({0,0,RIGHT,0});

    while (q.size() > 0) {
        Road curRoad = q.front(); q.pop();
        
        if (curRoad.getMinCost() < curRoad.cost) { continue; } // 같은 칸, 같은 방향의 경로 중 최소비용인 경우만 이동 진행
        
        if (curRoad.r == N-1 && curRoad.c == N-1) { // 도착
            if (res > curRoad.cost) { res = curRoad.cost; }
            continue;
        }

        for (int nextDir : dirs) {
            if (abs(nextDir - curRoad.dir) == 2)  { continue; } // 다시 뒤로가는 방향이면 안 함
            Road nextRoad = curRoad;
            if (nextRoad.build(nextDir)) {
                // 같은 칸, 같은 방향의 경로 중 최소비용인 경우만 기록 & push
                if (nextRoad.getMinCost() > nextRoad.cost) {
                    nextRoad.setMinCost();
                    q.push(nextRoad);
                }
            }
        }
    }

    return res;
}
