#include <iostream>
#include <vector>

using namespace std;
int board[9][9];
int done = 0;

struct Blank{
    int r;
    int c;
};

vector<Blank> blanks;
int blank_cnt = 0;

// 숫자 n이 빈칸에 적절한지 true/false로 반환
bool isCandi(int r, int c, int n){
    for(int i = 0; i < 9; i++){
        // 가로
        if (board[r][i] == n)
            return false;
        // 세로
        if (board[i][c] == n)
            return false;
    }

    // 사각 범위
    for(int i = (r/3)*3; i < (r/3)*3 + 3; i++){
        for(int j = (c/3)*3; j < (c/3)*3 + 3; j++){
            if (board[i][j] == n)
                return false;
        }
    }
    return true;
}

void DFS(int L){
    if(L == blank_cnt){
        // 답 찾으면 출력해주고, done 전역 flag 변수 1로 수정
        for(int r = 0; r < 9; r++){
            for(int c = 0; c < 9; c++){
                printf("%d ", board[r][c]);
            }
            printf("\n");
        }
        done = 1;
        return;
    }

    int r, c;
    r = blanks[L].r;
    c = blanks[L].c;

    // 0~9를 돌면서 (r, c) 위치의 빈칸이 적절한지 체크, done은 스도쿠 완료 여부 전체 전연변수
    for(int i = 0; i < 9; i++){
        if (isCandi(r, c, (i+1)) && done == 0){
            board[r][c] = (i+1);
            DFS(L+1);
            board[r][c] = 0;
        }
    }
}

int main(void){
    // input
    for(int r = 0; r < 9; r++){
        for(int c = 0; c < 9; c++){
            scanf("%d", &board[r][c]);
            if(board[r][c] == 0){
                Blank b;
                b.r = r;
                b.c = c;
                blanks.push_back(b);
                blank_cnt++;
            }
        }
    }

    DFS(0);
    
    return 0;
}
