#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

long long solution(int n, int m, int y, int x, vector<vector<int>> queries) {
    long long answer = 0;
    long long sx = x;
    long long ex = x;
    long long sy = y;
    long long ey = y;
    int dir, dx;
    // printf("%d %d %d %d \n", sx, ex, sy, ey);
    // 목적위치에서 반대로 가용 범위를 찾아감
    for(int i = queries.size() - 1; i >= 0; i--){
        dir = queries[i][0];
        dx = queries[i][1];
        // printf("%d : %d %d\n", i, queries[i][0], queries[i][1]);
        switch(dir){
            // 열 다시 증가
            case 0:
                if(sx != 0)
                    sx += dx;
                    if(sx > m-1)
                        sx = m-1;
                ex += dx;
                if(ex > m-1)
                    ex = m-1;
                break;
            // 열 다시 감소 
            case 1:
                sx -= dx;
                if(sx < 0)
                    sx = 0;
                if(ex != m-1)
                    ex -= dx;
                break;
            // 행 다시 증가
            case 2:
                if(sy != 0)
                    sy += dx;
                    if(sy > n-1)
                        sy = n-1;
                ey += dx;
                if(ey > n-1)
                    ey = n-1;
                break;
            // 행 다시 감소
            case 3:
                sy -= dx;
                if(sy < 0)
                    sy = 0;
                if(ey != n-1)
                    ey -= dx;
                break;
            default:
                break;
        }
        if(sx > m-1 || ex < 0 || sy > n-1 || ey < 0)
            return 0;
    }
    return (ex - sx + 1) * (ey - sy + 1);
}
