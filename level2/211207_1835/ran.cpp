#include <string>
#include <vector>
#include <cmath>

using namespace std;
string name = "ACFJMNRT";
int N;
bool selected[8] = { false,false,false,false,false,false,false,false };
string line = "        "; // 현재줄
vector<string> conditions; // 모든 조건
int res = 0;


bool isVaild() {
    int id1 = -1, id2 = -1;
    for (int i = 0; i < N; ++i) {
        id1 = line.find(conditions[i][0]);
        id2 = line.find(conditions[i][2]);
        if (id1 == string::npos || id2 == string::npos) continue;

        int number = conditions[i][4] - '0' + 1;
        switch (conditions[i][3]) {
        case '=':
            if (abs(id1 - id2) == number) continue;
            else return false;
        case '<':
            if (abs(id1 - id2) < number) continue;
            else return false;
        case '>':
            if (abs(id1 - id2) > number) continue;
            else return false;
        }
    }
    return true;
}

void push(int lineId) {
    if (lineId == 8) {
        res++;
        return;
    }

    for (int personId = 0; personId < 8; ++personId) {
        if (selected[personId] == true) continue;
        line[lineId] = name[personId];
        selected[personId] = true;

        if (!isVaild()) {
            selected[personId] = false;
            line[lineId] = ' ';
            continue;
        }
        push(lineId + 1);
        selected[personId] = false;
        line[lineId] = ' ';
    }

}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    // 초기화
    N = n;
    name = "ACFJMNRT";
    for (int i = 0; i < 8; i++) {
        selected[i] = false;
    }
    line = "        ";
    res = 0;
    conditions = data;

    push(0);
    return res;
}