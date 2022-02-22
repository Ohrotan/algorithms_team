#include <vector>

using namespace std;
int N;
vector<int> apeach;
vector<int> ryan;
vector<int> result;
int maxDiff = 0;

int getApeachScore(int i) {
    int score = 0;
    for (; i < 10; ++i) {
        if (apeach[i] > 0) {
            score += 10-i;
        }
    }
    return score;
}

bool isNewResult() {
    if (maxDiff == 0) return false;
    for(int i = 10; i >= 0; --i) {
        if (result[i] < ryan[i]) return true;
        if (result[i] > ryan[i]) return false;
    }
    return false;
}

void dfs(int i, int remainCnt, int apScore, int ryScore) {
    if (remainCnt == 0 || i == 10) { 
        apScore += getApeachScore(i);
        ryan[10] = remainCnt;
        int diff = ryScore - apScore;
        if (diff > maxDiff || (diff == maxDiff && isNewResult()) ) {
            maxDiff = diff;
            result = ryan;
        }
        return;
    }
    
    if (remainCnt > apeach[i]) {
        ryan[i] = apeach[i]+1;
        remainCnt -= ryan[i];
        
        dfs(i+1, remainCnt, apScore, ryScore+(10-i));
        
        remainCnt += ryan[i];
        ryan[i] = 0;
    }
    
    if (apeach[i] > 0) {
        apScore += 10-i;
    }
    dfs(i+1, remainCnt, apScore, ryScore);
}

vector<int> solution(int n, vector<int> info) {
    N = n;
    apeach = info;
    ryan.assign(11,0);
    dfs(0,N,0,0);
    if (result.size() == 0) { result.push_back(-1); }
    return result;
}
