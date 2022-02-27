// 시간초과~~ 수정예정~~
#include <iostream>
#include <set>
#include <vector>

using namespace std;
int board[9][9];

struct Blank{
    int r;
    int c;
    set<int> candi = {1, 2, 3, 4, 5, 6, 7, 8, 9};
};

vector<Blank> blanks;
int blank_cnt = 0;

void DFS(int L){
    if(L == blank_cnt){
        for(int r = 0; r < 9; r++){
            for(int c = 0; c < 9; c++){
                printf("%d ", board[r][c]);
            }
            printf("\n");
        }
        return;
    }

    int r, c;
    set<int> candi;
    r = blanks[L].r;
    c = blanks[L].c;
    candi = blanks[L].candi;
    
    for(int i = 0; i < 9; i++){
        if (candi.find(board[r][i]) == candi.end())
            continue;
        // 가로
        candi.erase(board[r][i]);
        // 세로
        if (candi.find(board[i][c]) == candi.end())
            continue;
        candi.erase(board[i][c]);
    }

    // 사각 범위
    for(int i = (r/3)*3; i < (r/3)*3 + 3; i++){
        for(int j = (c/3)*3; j < (c/3)*3 + 3; j++){
            if (candi.find(board[i][j]) == candi.end())
                continue;
            candi.erase(board[i][j]);
        }
    }

    vector<int> candi_ {candi.begin(), candi.end()};

    // for(int i = 0; i < candi.size(); i++){
    //     printf("L: %d, candi: %d \n", L, candi_[i]);
    // }

    for(int i = 0; i < candi.size(); i++){
        board[r][c] = candi_[i];
        DFS(L+1);
        board[r][c] = 0;
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
