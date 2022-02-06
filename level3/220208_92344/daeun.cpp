// 마지막 3개 시간 초과
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    for (int i = 0; i < skill.size(); i++){
        // 공격, 방어 계산
        int r1, c1, r2, c2;
        r1 = skill[i][1];
        c1 = skill[i][2];
        r2 = skill[i][3];
        c2 = skill[i][4];
        for (int y = r1; y < r2 + 1; y++){
            for (int x = c1; x < c2 + 1; x++){
                if(skill[i][0] == 1){
                    board[y][x] -= skill[i][5];
                }
                else{
                    board[y][x] += skill[i][5];
                }
            }
        }
    }
    
    // 파괴되지 않은 건물 count
    for (int y = 0; y < board.size(); y++){
        for (int x = 0; x < board[0].size(); x++){
            if (board[y][x] > 0)
                answer++;
        }
    }
    return answer;
}
