// 8!*100, 완전 탐색 
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void getAllLineCase(int& count, vector<string>& data, vector<char>& characters, vector<char>& choicedC, vector<bool>& choiced, int depth);int findIdxOfVector(vector<char> choicedC, char c);
int solution(int n, vector<string> data) {
    int answer = 0;
    int count = 0;
    
    vector<char> characters = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    vector<char> choicedC;
    vector<bool> choiced(8);
    
    getAllLineCase(count, data, characters, choicedC, choiced, 0);
    answer = count;
    
    return answer;
}

void getAllLineCase(int& count, vector<string>& data, vector<char>& characters, vector<char>& choicedC, vector<bool>& choiced, int depth) {
    if (depth == 8) {  // 8명을 모두 나열했을 때
        // 각 조건을 부합하는지 확인
        bool isPerfectCase = true;
        // cout << choicedC[4] << choicedC[5] << choicedC[6] << choicedC[7] << " ";
        for (int i = 0; i < data.size(); ++i) {
            string condition = data[i];
            int a = condition.at(0);
            int b = condition.at(2);
            char smallBig = condition.at(3);
            int len = condition.at(4) - '0';
            int aIdx = findIdxOfVector(choicedC, a);
            int bIdx = findIdxOfVector(choicedC, b);
            int big = bIdx > aIdx ? bIdx : aIdx;
            int small = bIdx < aIdx ? bIdx : aIdx;
            if (big == 9999 || small == 9999) {
                cout << "Error finding index";
            }
            if (smallBig == '=') {
                if ((big - small) != (len+1)) {
                    isPerfectCase = false;
                    break;
                }
            } else if (smallBig == '<') {
                if (!((big - small) < (len+1))) {
                    isPerfectCase = false;
                    break;
                }
            } else if (smallBig == '>') {
                if (!((big - small) > (len+1))) {
                    isPerfectCase = false;
                    break;
                }
            }
        }
        if (isPerfectCase == true) {
            ++count;
        }
    }
    
    // 8명을 나열하는 모든 경우 생성
    for (int i = 0; i <= 7; ++i) {
        if (choiced[i] == false) {
            choicedC.push_back(characters[i]);
            choiced[i] = true;
            getAllLineCase(count, data, characters, choicedC, choiced, depth+1);
            choiced[i] = false;
            choicedC.pop_back();
        }
    }
}

int findIdxOfVector(vector<char> choicedC, char c) {
    for (int i = 0; i < choicedC.size(); ++i) {
        if (choicedC[i] == c) {
            return i;
        }
    }
    return 9999;
}
