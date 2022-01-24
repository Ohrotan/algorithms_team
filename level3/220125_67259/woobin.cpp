#include <vector>
#include <iostream>
#define MAX 99999999
using namespace std;

const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, 1, 0, -1};
int costMap[26][26]; // 맵에다 해당 지점까지 가는 최소비용을 업데이트할거임
bool visit[26][26]; // 방문여부
int N = 0;
int answer = MAX;

void dfs(int cy, int cx, int direction, int sum) {
    // 이미 구한 답보다 구하고 있는 비용이 더 클 때
    if(sum > answer) {
        return;
    }
    
    // 코너를 최소로 해서 갈 수 있는 곳인데 굳이 여러번 돌아서 sum이 더 높을 때
    if(costMap[cy][cx] < sum) {
        return;
    }
    
    // 최소비용으로 업데이트
    costMap[cy][cx] = sum < costMap[cy][cx] ? sum : costMap[cy][cx];
    
    if(cy == N - 1 && cx == N - 1) {
        answer = sum < answer ? sum : answer;
        return;
    }
    
    for(int i = 0; i < 4; i++) {
        // 연속 같은 방향이 나오면 조금이라도 더 빨리 갈 수 있게함
        int dir = (direction + i) % 4;
        int ny = cy + dy[dir];
        int nx = cx + dx[dir];
        if(ny < 0 || ny > N - 1 || nx < 0 || nx > N - 1 || visit[ny][nx]) {
            continue;
        }
        
        // 백트래킹
        visit[ny][nx] = true;
        int nSum = ((direction == dir) || (direction == 4)) ? sum + 100 : sum + 600;
        dfs(ny, nx, dir, nSum);
        visit[ny][nx] = false;
    }
}

int solution(vector<vector<int>> board) {
    N = board.at(0).size();
    
    // 배열로 초기화, 최소비용을 구할 것이므로 각 지점의 최소비용 값을 MAX로 업데이트
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(board.at(i).at(j) == 1) {
                visit[i][j] = true;
            }
            costMap[i][j] = MAX;
        }
    }
    
    visit[0][0] = true;
    dfs(0, 0, 4, 0);
    
    return answer;
}
