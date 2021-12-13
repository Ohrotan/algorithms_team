#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> boardTemp;
vector<tuple<char, int, int>> sortedNameInCurrentBoard;
string answerTemp;
int mTemp;
int nTemp;



void SortName();
void FindAnswer();
bool CheckConnection(int, int, int, int, int);
bool CheckGoVertical(int, int, int, int);
bool CheckGoHorizontal(int, int, int, int);




string solution(int m, int n, vector<string> board) {

    ////////////////전역변수 초기화 구간///////////////
    string answer = "";
    boardTemp = board;
    answerTemp = answer;
    mTemp = m;
    nTemp = n;
    vector<tuple<char, int, int>> resetVector;
    sortedNameInCurrentBoard = resetVector;
    ////////////////////////////////////////////////

    SortName();
    FindAnswer();

    answer = answerTemp;

    return answer;
}

void SortName() {//알파벳이 정렬되고, 두 개의 동일한 알파벳이 나란히 들어가게 된다.

    for (int i = 0; i < mTemp; i++) {
        for (int j = 0; j < nTemp; j++) {
            if (boardTemp[i][j] != '.' && boardTemp[i][j] != '*') {
                sortedNameInCurrentBoard.push_back({ boardTemp[i][j], i, j });
            }
        }
    }

    sort(sortedNameInCurrentBoard.begin(), sortedNameInCurrentBoard.end());
}

void FindAnswer() {

    for (int i = 0; i < sortedNameInCurrentBoard.size(); i = i + 2) {
        if (CheckConnection(get<1>(sortedNameInCurrentBoard.at(i)), get<1>(sortedNameInCurrentBoard.at(i + 1)),
            get<2>(sortedNameInCurrentBoard.at(i)), get<2>(sortedNameInCurrentBoard.at(i + 1)), i) == true)//두 좌표가 연결가능하면
        {
            sortedNameInCurrentBoard.erase(sortedNameInCurrentBoard.begin() + i);//알파벳 삭제
            sortedNameInCurrentBoard.erase(sortedNameInCurrentBoard.begin() + i);//두개 있을테니 한번 더 삭제
            i = -2;//연결한 알파벳은 지우고 다시 첫 알파벳부터 검사하기 위함
        }//두 좌표가 연결 불가능 하면 다음 알파벳으로 넘어감
    }

    if (sortedNameInCurrentBoard.size() != 0) {
        answerTemp = "IMPOSSIBLE";//정렬 해 놓은 알파벳이 남아있으면 다 못 지운거
    }

}

bool CheckConnection(int y1, int y2, int x1, int x2, int nameLocation) {

    //가로로 일자로 놓여있는 경우
    if (y1 != y2 && x1 == x2) {
        int yLow;
        int yHigh;
        if (y1 > y2) {
            yLow = y2;
            yHigh = y1;
        }
        else {
            yLow = y1;
            yHigh = y2;
        }
        for (int i = yLow + 1; i <= yHigh - 1; i++) {
            if (boardTemp[i][x1] == '.')continue;
            else return false;//도중에 다른 알파벳이나 막힌 곳을 발견 할 경우 실패! 두둥탁
        }
        answerTemp = answerTemp + boardTemp[y1][x1];
        boardTemp[y1][x1] = '.';
        boardTemp[y2][x2] = '.';
        return true;
    }

    //가로로 일자로 놓여있는 경우
    if (y1 == y2 && x1 != x2) {
        int xLow;
        int xHigh;
        if (x1 > x2) {
            xLow = x2;
            xHigh = x1;
        }
        else {
            xLow = x1;
            xHigh = x2;
        }
        for (int i = xLow + 1; i <= xHigh - 1; i++) {
            if (boardTemp[y1][i] == '.')continue;
            else return false;
        }
        answerTemp = answerTemp + boardTemp[y1][x1];
        boardTemp[y1][x1] = '.';//이 까지 왔다는 건 장애물이 없었다는 뜻이므로 성공~
        boardTemp[y2][x2] = '.';
        return true;
    }



    if (y1 != y2 && x1 != x2) {
        if (CheckGoHorizontal(y1, y2, x1, x2) == true) return true;
        else if (CheckGoVertical(y1, y2, x1, x2) == true)return true;
        else return false;
    }


}

//y1,x1 좌표에서 수직으로 출발하는 경우 따짐
bool CheckGoVertical(int y1, int y2, int x1, int x2) {


    if (y2 > y1 && x2 > x1) {             //y1,x1 기준 ↑→로 y2,x2 가는 방법 따짐
        for (int i = y1 + 1; i <= y2; i++) {
            if (boardTemp[i][x1] == '.') continue;
            else return false;
        }
        for (int i = x1 + 1; i < x2; i++) {
            if (boardTemp[y2][i] == '.') continue;
            else return false;
        }
        answerTemp = answerTemp + boardTemp[y1][x1];
        boardTemp[y1][x1] = '.';
        boardTemp[y2][x2] = '.';
        return true;
    }
    else if (y2 > y1 && x1 > x2) {       //y1,x1 기준 ↑←로 y2,x2 가는 방법 따짐
        for (int i = y1 + 1; i <= y2; i++) {
            if (boardTemp[i][x1] == '.') continue;
            else return false;
        }
        for (int i = x1 - 1; i > x2; i--) {
            if (boardTemp[y2][i] == '.') continue;
            else return false;
        }
        answerTemp = answerTemp + boardTemp[y1][x1];
        boardTemp[y1][x1] = '.';
        boardTemp[y2][x2] = '.';
        return true;
    }
    else if (y1 > y2 && x1 > x2) {       //y1,x1 기준 ↓←로 y2,x2 가는 방법 따짐
        for (int i = y1 - 1; i >= y2; i--) {
            if (boardTemp[i][x1] == '.') continue;
            else return false;
        }
        for (int i = x1 - 1; i > x2; i--) {
            if (boardTemp[y2][i] == '.') continue;
            else return false;
        }
        answerTemp = answerTemp + boardTemp[y1][x1];
        boardTemp[y1][x1] = '.';
        boardTemp[y2][x2] = '.';
        return true;
    }
    else {                              //y1,x1 기준 ↓→로 y2,x2 가는 방법 따짐
        for (int i = y1 - 1; i >= y2; i--) {
            if (boardTemp[i][x1] == '.') continue;
            else return false;
        }
        for (int i = x1 + 1; i < x2; i++) {
            if (boardTemp[y2][i] == '.') continue;
            else return false;
        }
        answerTemp = answerTemp + boardTemp[y1][x1];
        boardTemp[y1][x1] = '.';
        boardTemp[y2][x2] = '.';
        return true;
    }
}

//y1,x1 좌표에서 수평으로 출발하는 경우 따짐
bool CheckGoHorizontal(int y1, int y2, int x1, int x2) {

    if (y2 > y1 && x2 > x1) {             //y1,x1 기준 →↑로 y2,x2 가는 방법 따짐
        for (int i = x1 + 1; i <= x2; i++) {
            if (boardTemp[y1][i] == '.') continue;
            else return false;
        }
        for (int i = y1 + 1; i < y2; i++) {
            if (boardTemp[i][x2] == '.') continue;
            else return false;
        }
        answerTemp = answerTemp + boardTemp[y1][x1];
        boardTemp[y1][x1] = '.';
        boardTemp[y2][x2] = '.';
        return true;
    }
    else if (y2 > y1 && x1 > x2) {       //y1,x1 기준 ←↑로 y2,x2 가는 방법 따짐
        for (int i = x1 - 1; i >= x2; i--) {
            if (boardTemp[y1][i] == '.') continue;
            else return false;
        }
        for (int i = y1 + 1; i < y2; i++) {
            if (boardTemp[i][x2] == '.') continue;
            else return false;
        }
        answerTemp = answerTemp + boardTemp[y1][x1];
        boardTemp[y1][x1] = '.';
        boardTemp[y2][x2] = '.';
        return true;
    }
    else if (y1 > y2 && x1 > x2) {       //y1,x1 기준 ←↓로 y2,x2 가는 방법 따짐
        for (int i = x1 - 1; i >= x2; i--) {
            if (boardTemp[y1][i] == '.') continue;
            else return false;
        }
        for (int i = y1 - 1; i > y2; i--) {
            if (boardTemp[i][x2] == '.') continue;
            else return false;
        }
        answerTemp = answerTemp + boardTemp[y1][x1];
        boardTemp[y1][x1] = '.';
        boardTemp[y2][x2] = '.';
        return true;
    }
    else {                              //y1,x1 기준 →↓로 y2,x2 가는 방법 따짐
        for (int i = x1 + 1; i <= x2; i++) {
            if (boardTemp[y1][i] == '.') continue;
            else return false;
        }
        for (int i = y1 - 1; i > y2; i--) {
            if (boardTemp[i][x2] == '.') continue;
            else return false;
        }
        answerTemp = answerTemp + boardTemp[y1][x1];
        boardTemp[y1][x1] = '.';
        boardTemp[y2][x2] = '.';
        return true;
    }
}


