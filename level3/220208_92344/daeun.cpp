// 해설 추가필요
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    // mask 생성
    int mask[1001][1001] = {0, };
    
    for (int i = 0; i < skill.size(); i++){
        // mask 계산
        int r1, c1, r2, c2;
        r1 = skill[i][1];
        c1 = skill[i][2];
        r2 = skill[i][3];
        c2 = skill[i][4];
        
        int degree = skill[i][5];
        if (skill[i][0] == 1)
            degree = -degree;
        
        mask[r1][c1] += degree;
        mask[r1][c2+1] += -degree;
        mask[r2+1][c1] += -degree;
        mask[r2+1][c2+1] += degree;
    }
    
    // 누적 더하기
    for (int y = 0; y < board.size()+1; y++){
        for (int x = 0; x < board[0].size(); x++){
            mask[y][x+1] = mask[y][x] + mask[y][x+1];
        }
    }

    for (int x = 0; x < board[0].size()+1; x++){
        for (int y = 0; y < board.size(); y++){
            mask[y+1][x] = mask[y][x] + mask[y+1][x];
        }
    }
    
    // mask와 board 더하기
    for (int y = 0; y < board.size(); y++){
        for (int x = 0; x < board[0].size(); x++){
            mask[y][x] += board[y][x];
        }
    }
    
    // 파괴되지 않은 건물 count
    for (int y = 0; y < board.size(); y++){
        for (int x = 0; x < board[0].size(); x++){
            if (mask[y][x] > 0)
                answer++;
        }
    }
    return answer;
}
