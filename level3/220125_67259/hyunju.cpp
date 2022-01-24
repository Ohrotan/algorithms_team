// 최대 (81.44ms, 4.27MB)
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void findPath(vector<vector<int>>& board, vector<vector<vector<int>>>& check, int x, int y, int beforeDir, int& N);
int solution(vector<vector<int>> board) {
    int answer = 0;
    
    int N = board.size();
    vector<vector<vector<int>>> check(N, vector(N, vector<int>(4, 9999999)));  // x, y, dir
    
    check[0][0][0] = 0;
    check[0][0][1] = 0;
    check[0][0][2] = 0;
    check[0][0][3] = 0;
    
    findPath(board, check, 0, 0, -1, N);
    
    int min = 9999999;
    for (int dir = 0; dir <= 3; ++dir) {
        if (min > check[N-1][N-1][dir])
            min = check[N-1][N-1][dir];
    }
    answer = min - 500;  // 맨 처음에 방향을 전환했다고 가정해서 500을 빼줌.
    
    return answer;
}

void findPath(vector<vector<int>>& board, vector<vector<vector<int>>>& check, int x, int y, int beforeDir, int& N) {
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    bool isFirst = true;
    
    for (int d = 0; d <= 3; ++d) {
        if (isFirst && (beforeDir != -1)) {  // 직선 우선 탐색 (맨 처음에 방향이 -1이므로 예외 처리)
            d = beforeDir;
        } else if (d == beforeDir) {  // 직선 중복 탐색 방지
            continue;
        }
        int nx = x + dx[d];
        int ny = y + dy[d];
        
        if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
            if (board[nx][ny] == 0) {
                if (beforeDir != d) {  // 회전
                    if (check[nx][ny][d] > check[x][y][beforeDir] + 600) { 
                        check[nx][ny][d] = check[x][y][beforeDir] + 600;
                        findPath(board, check, nx, ny, d, N);    
                    }
                } else {  // 직선
                    if (check[nx][ny][d] > check[x][y][beforeDir] + 100) {
                        check[nx][ny][d] = check[x][y][beforeDir] + 100;
                        findPath(board, check, nx, ny, d, N);    
                    }
                }
            }
        }
        if (isFirst) {  // 직선 우선 이후 회전 3가지 위해 세팅
            d = -1;
            isFirst = false;
        }
    }
    
}
