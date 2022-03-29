#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

int startId = 0, endId; // 현재 검사 중인 보석위치
int resCnt, resStart, resEnd; // 쇼핑한 보석의 개수, 쇼핑한 보석의 시작점, 끝점
unordered_map<string, int> gemCnts; // 각 보석 종류별 개수

vector<int> solution(vector<string> gems) {
    set<string> kind(gems.begin(), gems.end()); // 보석 종류 구하기

    for (int i = 0; i < gems.size(); ++i) {
        gemCnts[gems[i]]++;
        if (gemCnts.size() == kind.size()) { // 모든 종류의 보석 개수가 1개 이상이 되었을 때
            endId = i; 
            break;
        }
    }
    resCnt = endId - startId;
    resStart = startId;
    resEnd = endId;

    while (endId < gems.size()) {
        string firstGem = gems[startId]; 
        // 현재 라인의 첫번째 보석을 먼저 제외시킴
        gemCnts[firstGem]--;
        startId++;

        if (gemCnts[firstGem] == 0) { 
            // 만약 현재 라인에 방금 제외시킨 보석이 더 없다면 뒤쪽 보석에 있는지 확인
            endId++;
            for (; endId < gems.size(); endId++) {
                gemCnts[gems[endId]]++;
                if (firstGem == gems[endId]) break; // 뒤쪽에 있으므로 break;
            }
            if (endId == gems.size()) break; // 끝까지 보석을 못 찾은 경우
        }
        
        // 직전과 비교해서 보석개수가 작은 경우만 result 
        if (resCnt > endId - startId) {
            resStart = startId;
            resEnd = endId;
            resCnt = endId - startId;
        }

    }

    return {resStart+1, resEnd+1};
}
