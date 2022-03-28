#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

int startId, endId, resCnt, resStart, resEnd;
unordered_map<string, int> gemCnts;

vector<int> solution(vector<string> gems) {
    set<string> kind(gems.begin(), gems.end());

    for (int i = 0; i < gems.size(); ++i) {
        gemCnts[gems[i]]++;
        if (gemCnts.size() == kind.size()) {
            endId = i;
            break;
        }
    }
    resCnt = endId - startId;
    resStart = startId;
    resEnd = endId;

    while (endId < gems.size()) {
        string firstGem = gems[startId];
        gemCnts[firstGem]--; startId++;

        if (gemCnts[firstGem] == 0) {
            endId++;
            for (; endId < gems.size(); endId++) {
                gemCnts[gems[endId]]++;
                if (firstGem == gems[endId]) break;
            }
            if (endId == gems.size()) break;
        }
        if (resCnt > endId - startId) {
            resStart = startId;
            resEnd = endId;
            resCnt = endId - startId;
        }

    }

    return {resStart+1, resEnd+1};
}
