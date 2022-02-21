#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> answer;
int diff = -1;

void calcScore(vector<int>& ryan, int ryanScore, int apeachScore) {
    int tempDiff = ryanScore - apeachScore;
    
    // ryan win, apeach lose
    if(tempDiff > 0) {
        if(tempDiff > diff) {
            diff = tempDiff;
            answer.assign(ryan.begin(), ryan.end());
        } else if(tempDiff == diff) {
            
            // 점수 같을 시 벡터를 0점 과녁부터 시작으로 reverse 한뒤 계산
            std::reverse(answer.begin(), answer.end());
            std::reverse(ryan.begin(), ryan.end());
            if(answer < ryan) {
                answer.assign(ryan.begin(), ryan.end());
            }
            std::reverse(answer.begin(), answer.end());
            std::reverse(ryan.begin(), ryan.end());
        }
    }
}

void assignArrow(vector<int>& ryan, vector<int>& apeach, int count, int idx, int ryanScore, int apeachScore) {
    if(count < 0) {
        return;
    }
    
    if(count == 0 || idx == 11) {
        ryan.at(10) += count;
        calcScore(ryan, ryanScore, apeachScore);
        ryan.at(10) -= count;
        return;
    }
    
    // assign ryan vector's idx +1
    if(apeach.at(idx) < count) {
        int temp = ryan.at(idx);
        int apeachOffset = apeach.at(idx) == 0 ? 0 : 10 - idx;
        ryan.at(idx) = apeach.at(idx) + 1;
        assignArrow(ryan, apeach, count - apeach.at(idx) - 1, idx + 1, ryanScore + (10 - idx), apeachScore - apeachOffset);
        ryan.at(idx) = temp;
    }
    
    // skip current idx
    assignArrow(ryan, apeach, count, idx + 1, ryanScore, apeachScore);
}

vector<int> solution(int n, vector<int> info) {
    vector<int> ryanArrows;
    ryanArrows.assign(11, 0);
    answer.assign(1, -1);
    
    int apeachAvailableScore = 0;
    for(int i = 0; i < info.size(); i++) {
        apeachAvailableScore = info.at(i) > 0 ? apeachAvailableScore + (10 - i) : apeachAvailableScore + 0;
    }
    
    assignArrow(ryanArrows, info, n, 0, 0, apeachAvailableScore);
    return answer;
}
