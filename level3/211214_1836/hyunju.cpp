// 각 알파벳과 그의 좌표를 담는 map을 이용하여 각 조건을 따지는 반복문을 이용하여 최적의 결과를 찾았음.
// 이미 선택한 타일들의 순서는 상관이 없다.
// 그리고 바로 앞에 고를 타일의 종류도 상관이 없다. 선택할 타일이 있기만 하면 된다. 
// 그 중에 A에 가장 가까운 타일을 고르기만 하면 된다. greedy 하게 풀었음.
#include <string>
#include <vector>
#include <deque>
#include <unordered_map>
#include <utility>
#include <unordered_set>
#include <iostream>

using namespace std;

bool isAvailable(vector<vector<char>> board2, int x1, int y1, int x2, int y2, char c, string already);

string theAnswer;
bool answerFound;
string solution(int m, int n, vector<string> board) {
    string answer = "";
    
    vector<vector<char>> board2(m, vector<char>(n));  // 알파벳 정보가 들어있는 2차원 보드
    unordered_map<char, vector<int>> um;  // 각 알파벳의 X,Y 좌표 2개 (x1, y1, x2, y2)
    
    // 초기화
    theAnswer = "";
    answerFound = false;
    string ans = "";
    string s;
    for (int x = 0; x < m; ++x) {
        s = board[x];
        for (int y = 0; y < n; ++y) {
            char c = s.at(y);
            if (c != '*' && c != '.') {
                um[c].push_back(x);
                um[c].push_back(y); 
            }
            board2[x][y] = s.at(y);
        }
    }
    
    // 결과 도출
    string nextStr = "";
    while (true) {
        string str = nextStr;
        bool found = false;
        // 답을 찾은 경우 탈출
        if (str.size() == um.size()) {
            theAnswer = str;
            answerFound = true;
            break;
        }
        // A부터 가능한 다음 타일을 선택
        for (char c = 'A'; c <= 'Z'; ++c) {
            if (um.count(c) == 0 || str.find(c) != string::npos) {
                continue;
            } else {
                int x1 = um[c][0];
                int y1 = um[c][1];
                int x2 = um[c][2];
                int y2 = um[c][3];
                if(isAvailable(board2, x1, y1, x2, y2, c, str)) {
                    // 다음 타일 선택
                    str.push_back(c);
                    nextStr = str;
                    found = true;
                    break;
                }
            }
        }
        if (!found) break;  // 답을 못찾은 경우의 탈출
    }
    
    if (answerFound == false) {
        answer = "IMPOSSIBLE";
        return answer;
    } else {
        answer = theAnswer;
        return answer;
    }
    
    return answer;
}

bool isAvailable(vector<vector<char>> board2, int x1, int y1, int x2, int y2, char c, string already) {
    bool avail1 = true;  // case1: x1, y1 -> x2, y1 -> x2, y2
    bool avail2 = true;  // case2: x1, y1 -> x1, y2 -> x2, y2
    
    int oper = x1 < x2 ? 1 : -1;
    for (int x = x1; x != x2; x=x+oper) {
        if (!(board2[x][y1] == '.' || board2[x][y1] == c || already.find(board2[x][y1]) != string::npos)) {
            avail1 = false;
            break;
        }
    }
    for (int x = x1; x != x2; x=x+oper) {
        if (!(board2[x][y2] == '.' || board2[x][y2] == c || already.find(board2[x][y2]) != string::npos)) {
            avail2 = false;
            break;
        }
    }

    oper = y1 < y2 ? 1 : -1;
    for (int y = y1; y != y2; y=y+oper) {
        if (!(board2[x2][y] == '.' || board2[x2][y] == c || already.find(board2[x2][y]) != string::npos)) {
            avail1 = false;
            break;
        }
    }
    
    for (int y = y1; y != y2; y=y+oper) {
        if (!(board2[x1][y] == '.' || board2[x1][y] == c || already.find(board2[x1][y]) != string::npos)) {
            avail2 = false;
            break;
        }
    }
    
    return (avail1 || avail2);
}
