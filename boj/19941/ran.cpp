#include <iostream>

using namespace std;
int N, K;
int eatenCnt;
string table;

int getEatableIndex(int i) {
    for (int j = max(0, i - K); j <= i + K; ++j) {
        if (table[j] == 'H') return j;
    }
    return -1;
}

void simulate() {
    for (int i = 0; i < N; ++i) {
        if (table[i] == 'P') {
            int idx = getEatableIndex(i);
            if (idx != -1) {
                table[idx] = 'X';  // 먹음
                eatenCnt++;
            }
        }
    }
}

int main() {
    cin >> N >> K;
    cin >> table;
    simulate();
    cout << eatenCnt << endl;
}
