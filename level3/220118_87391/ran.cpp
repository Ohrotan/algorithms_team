#include <vector>

using namespace std;
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

long long solution(int R, int C, int x, int y, vector<vector<int>> queries) {
    
    int startC = y;  // 가능한 시작점의 열 범위의 첫 index
    int endC = y;    // 가능한 시작점의 열 범위의 끝 index
    int startR = x;
    int endR = x;
    
    // 마지막 명령부터 거꾸로 수행
    for (int i = queries.size() - 1; i >= 0; --i) {
        int dir = queries[i][0];  // 방향
        int cnt = queries[i][1];  // 이동할 칸
        switch (dir) {
            case LEFT:
                // 열 범위에 0이 있다면 시작 index는 0으로 유지하고, 끝 index만 늘림
                // 왼쪽이동이니까 반대로 오른쪽 이동으로 계산해서 colum 값을 더함
                if (startC != 0) startC += cnt;
                endC += cnt;
                break;
            case RIGHT:
                if (endC != C - 1) endC -= cnt;
                startC -= cnt;
                break;
            case UP:
                if (startR != 0) startR += cnt;
                endR += cnt;
                break;
            case DOWN:
                if (endR != R - 1) endR -= cnt;
                startR -= cnt;
                break;
        }
        
        // 값 보정
        if (startC < 0) startC = 0;
        if (endC  >= C) endC   = C - 1;
        if (startR < 0) startR = 0;
        if (endR  >= R) endR   = R - 1;

        // 불가능한 경우
        if (startR >= R || endR < 0 || startC >= C || endC < 0) {
            return 0;
        }
    }
    return static_cast<long long>(endC - startC + 1)*(endR - startR + 1);
}














