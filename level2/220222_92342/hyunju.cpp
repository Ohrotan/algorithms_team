// 과녁 점수가 높은 앞에서부터 완탐. 선택 or not
// 그리고 최소한의 화살로 어피치를 이기고 남은 화살은 0점에 몰아주는 것이 포인트
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int maxPoint;  // 완탐 중 점수 차의 max point
int maxPointLastIndex;  // max point 인 경우의 가장 낮은 점수의 과녁 점수 index
vector<int> maxPointVector;  // max point 인 경우의 점수 배열
vector<int> arrowsForPoint;  // 라이언이 점수를 획득하기 위해 필요한 화살 개수의 배열
void searchAllCases(int rest_arrows, int index, int pointSum, vector<int>& traceArrows, int lastIndex);
// 탐색 중 사용하고 남은 화살 개수, 과녁 점수 index, index까지 점수 차의 합, 화살 개수 배열 trace, 화살을 맞춘 마지만 과녁 index

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    vector<int> traceArrows;
    
    maxPoint = -1;
    maxPointLastIndex = -1;
    for (int i : info) {
        arrowsForPoint.push_back(i+1);
    }
    searchAllCases(n, -1, 0, traceArrows, -1);
    if (maxPoint == -1 || maxPoint == 0) {  // 라이언이 지거나 비길 때 
        answer.push_back(-1);
    } else {
        answer = maxPointVector;    
    }
    
    
    return answer;
}

void searchAllCases(int rest_arrows, int index, int pointSum, vector<int>& traceArrows, int lastIndex) {
    // 마지막(점수 0)까지 과녁을 돌고 총 점수 계산 및 저장
    if (index == 10) {
        vector<int> tmpTraceArrows = traceArrows;
        if (rest_arrows > 0) {  // 화살이 남으면 0점에 몰아준다.
            tmpTraceArrows[10] += rest_arrows;
            lastIndex = 10;
        }
        if (pointSum > maxPoint || (pointSum == maxPoint && maxPointLastIndex <= lastIndex)) {
            maxPointVector = tmpTraceArrows;
            maxPoint = pointSum;
            maxPointLastIndex = lastIndex;
        }        
        return;
    }
    index = index+1;
    // 선택 (득점)
    if (rest_arrows >= arrowsForPoint[index]) {
        traceArrows.push_back(arrowsForPoint[index]);
        searchAllCases(rest_arrows-arrowsForPoint[index], index, pointSum+(10-index), traceArrows, index);
        traceArrows.pop_back();
    }
    
    // 미선택 (실점)
    traceArrows.push_back(0);
    int minusPoint;
    if (arrowsForPoint[index] == 1) {
        minusPoint = 0;  // 둘 다 화살 0개면 실점도 없다.
    } else {
        minusPoint = 10-index;
    }
    searchAllCases(rest_arrows, index, pointSum-minusPoint, traceArrows, lastIndex);
    traceArrows.pop_back();
}
