#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int map[25][25];
int visited[25][25] = {0, };
int cost = 2147000000; // int 형 최대값
int N;

struct CAR{
    int x;
    int y;
    int dir;
};

void dfs(int map[][25], CAR car, int cur_cost){
    
    // if(N == 3)
    //     printf("%d %d %d %d %d\n", cost, cur_cost, car.y, car.x, car.dir);
    
    if(cur_cost >= cost){
        return;
    }
      
    if (car.y == N-1 && car.x == N-1){
        cost = cur_cost;
        return;
    }
    // printf("aaaaa\n");
    for(int i = 0; i < 4; i++){
        int ny = car.y + dy[i];
        int nx = car.x + dx[i];
        int nd = i;
        if(ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] == 1 || map[ny][nx] == 1)
            continue;
        // printf("aaaaa\n");
        int next_cost;
        visited[ny][nx] = 1;
        next_cost = cur_cost + 100;
        if(car.dir != nd && car.dir != -1){
            next_cost += 500;
        }
        dfs(map, {ny, nx, nd}, next_cost);
        visited[ny][nx] = 0;
    }
}

//dfs
int solution(vector<vector<int>> board) {
    N = board.size();
    // printf("%d\n", N);
    CAR car = {0, 0, -1};
    for(int y = 0; y < N; y++){
        for(int x = 0; x < N; x++){
            map[y][x] = board[y][x];
        }
    }
    visited[0][0] = 1;
    dfs(map, car, 0);
    
    return cost;
}
