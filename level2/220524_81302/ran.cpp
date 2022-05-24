#include <string>
#include <vector>

using namespace std;

vector<string> currentRoom;

int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};

int dgi[4] = {-1, -1, 1, 1};
int dgj[4] = {-1, 1, -1, 1};

int i, j;

bool isValid(int _i, int _j) {
    if (_i > 4 || _j > 4 || _i < 0 || _j < 0) {
        return false;
    }
    return true;
}

bool checkDiagonal() {
    int ni = 0, nj = 0;
    for (int dirNum = 0; dirNum < 4; ++dirNum) {
        ni = i + dgi[dirNum];
        nj = j + dgj[dirNum];
        if (isValid(ni, nj)) {
            switch (currentRoom[ni][nj]) {
                case 'P': {
                    // 대각선에 사람있으면, 그 아래 옆으로 빈책상 1개라도 있으면 거리두기 실패
                    if (currentRoom[ni][j] == 'O') {
                        return false;
                    }
                    if (currentRoom[i][nj] == 'O') {
                        return false;
                    }
                    break;
                }
                default:
                    break;
            }
        }
    }
    return true;
}

bool checkLine() {
    int ni = 0, nj = 0;
    for (int dirNum = 0; dirNum < 4; ++dirNum) {
        ni = i + di[dirNum];
        nj = j + dj[dirNum];
        if (isValid(ni, nj)) {
            switch (currentRoom[ni][nj]) {
                // 빈 책상이면 그 옆(맨해튼거리2)이 사람이면 거리두기 실패
                case 'O': {
                    if (isValid(ni + di[dirNum], nj + dj[dirNum])) {
                        if (currentRoom[ni + di[dirNum]][nj + dj[dirNum]] == 'P') {
                            return false;
                        }
                    }
                    break;
                }
                // 바로 옆이 사람이니까 거리두기 실패
                case 'P': {
                    return false;
                }
                default:
                    break;
            }
        }
    }
    return true;
}

bool isPersonOK() {
    if (checkLine()) {
        if (checkDiagonal()) {
            return true;
        }
    }
    return false;
}

int isRoomOK() {
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; ++j) {
            if (currentRoom[i][j] == 'P') {
                if (isPersonOK() == false) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> res;
    for (int room = 0; room < 5; room++) {
        currentRoom = places[room];
        res.push_back(isRoomOK());
    }
    return res;
}
