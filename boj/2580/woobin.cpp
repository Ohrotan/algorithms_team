#include <iostream>
#include <vector>
#include <cstring>
#define MAX 9

int sudoku[MAX][MAX];
bool flag = false;
std::vector<std::pair<int, int>> blanks;

bool checkRowsAndCols(int num, int y, int x) {
    bool bRet = true;
    for(int idx = 0; idx < MAX; idx++) {
        if((sudoku[y][idx] == num) || (sudoku[idx][x] == num)) {
            bRet = false;
            break;
        }
    }
    
    return bRet;
}

bool checkRectangle(int num, int y, int x) {
    bool bRet = true;
    int startY = 3 * (y / 3);
    int startX = 3 * (x / 3);
    
    for(int i = startY; i < startY + 3; i++) {
        for(int j = startX; j < startX + 3; j++) {
            if(sudoku[i][j] == num) {
                bRet = false;
                break;
            }
        }
        if(!bRet) {
            break;
        }
    }
    
    return bRet;
}

bool checkAvailable(int num, int y, int x) {
    bool bRet = false;
    if((checkRowsAndCols(num, y, x)) && (checkRectangle(num, y, x))) {
        bRet = true;
    }
    
    return bRet;
}

void calcSudoku(int count) {
    if(flag) {
        return;
    }
    
    if(count == static_cast<int>(blanks.size())) {
        for(int i = 0; i < MAX; i++) {
            for(int j = 0; j < MAX; j++) {
                std::cout << sudoku[i][j] << " ";
            }
            std::cout << "\n";
        }
        flag = true;
        return;
    }
    
    for(int num = 1; num <= MAX; num++) {
        int y = blanks.at(count).first;
        int x = blanks.at(count).second;
        if(checkAvailable(num, y, x)) {
            sudoku[y][x] = num;
            calcSudoku(count + 1);
            sudoku[y][x] = 0;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    memset(sudoku, 0, sizeof(sudoku));
    
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            std::cin >> sudoku[i][j];
            if(sudoku[i][j] == 0) {
                blanks.push_back({i, j});
            }
        }
    }
    
    calcSudoku(0);
    
    return 0;
}
