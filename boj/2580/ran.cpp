#include <vector>
#include <iostream>

using namespace std;

int pan[81][81];
vector<pair<int, int>> blanks;
vector<bool> rowNum;
vector<bool> colNum;
vector<bool> squareNum;
vector<int> prom;

void printAndExit() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << pan[i][j] << " ";
        }
        cout << "\n";
    }
    exit(0);
}

void checkRows(int c) {
    rowNum.assign(10, false);
    for (int i = 0; i < 9; ++i) {
        rowNum[pan[i][c]] = true;
    }
}

void checkColumns(int r) {
    colNum.assign(10, false);
    for (int i = 0; i < 9; ++i) {
        colNum[pan[r][i]] = true;
    }
}

void checkSquare(int r, int c) {
    squareNum.assign(10, false);
    r = (r / 3) * 3;
    c = (c / 3) * 3;
    for (int i = r; i < r + 3; ++i) {
        for (int j = c; j < c + 3; ++j) {
            squareNum[pan[i][j]] = true;
        }
    }
}

//pan[r][c]에 들어갈 수 있는 숫자리스트 prom
void makeProm(int r, int c) {
    checkRows(c);
    checkColumns(r);
    checkSquare(r, c);
    prom.clear();
    for (int j = 1; j < 10; ++j) {
        if (rowNum[j] == false && colNum[j] == false && squareNum[j] == false) {
            prom.push_back(j); // 셋다 없는 숫자인 경우
        }
    }
}

void dfs(int i) {
    if (i >= blanks.size()) { printAndExit();}
    int r = blanks[i].first, c = blanks[i].second;
    makeProm(r, c);
    vector<int> nums(prom);
    for (int num: nums) {
        pan[r][c] = num;
        dfs(i + 1);
    }
    pan[r][c] = 0;
}

int main() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            scanf("%d", &pan[i][j]);
            if (pan[i][j] == 0) { blanks.push_back({i, j}); }
        }
    }
    dfs(0);
    return 0;
}
