#include <iostream>
#include <map>

using namespace std;
int N;
char words[10][8];
int scores[27]; // 0=A
map<int, string> scoreMap;
int maxNum = 9;
long long res = 0;


void init() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 8; ++j) {
            words[i][j] = ' ';
        }
    }
}

void readWords() {
    cin >> N;
    init();
    string tmp;
    for (int i = 0; i < N; ++i) {
        cin >> tmp;
        int k = 0;
        for (int j = 8 - tmp.size(); j < 8; ++j) {
            words[i][j] = tmp[k++];
        }
    }
}

void calculateScore() {
    int weight = 1;
    for (int j = 7; j >= 0; --j) {
        for (int i = 0; i < N; ++i) {
            scores[words[i][j] - 'A'] += weight;
        }
        weight *= 10;
    }
}


void makeScoreMap() {
    for (int i = 0; i < 27; ++i) {
        if (scores[i] > 0) {
            if (scoreMap.find(scores[i]) == scoreMap.end()) {
                string letter(1,i + 'A');
                scoreMap.insert({scores[i], letter});
            } else {
                scoreMap[scores[i]].push_back(i + 'A');
            }
        }
    }
}

void replaceNumber() {
    for (auto iter = scoreMap.rbegin(); iter != scoreMap.rend(); iter++) {
        int cnt = iter->second.size();
        while (cnt > 0) {
            res += static_cast<long long>(iter->first * maxNum);
            maxNum--;
            cnt--;
        }
    }

}
int main() {
    readWords();
    calculateScore();
    makeScoreMap();
    replaceNumber();
    cout << res << endl;
}
