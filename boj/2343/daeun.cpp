#include <iostream>

using namespace std;
#define MAX_N 100000 + 2

int N, M;
int lec[MAX_N];
int total;

void input_data() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> lec[i];
        total += lec[i];
    }
}

bool check(int m) {
    int cnt = 1;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (lec[i] > m) return false;
        if (sum + lec[i] > m) {
            cnt++;
            sum = lec[i];
        }
        else sum += lec[i];
        if (cnt > M) return false;
    }
    return true;
}

int solve() {
    int s = 0;
    int e = total;
    int m, res;

    while (s <= e) {
        m = (s + e) / 2;
        if (check(m)) {
            e = m - 1;
            res = m;
        }
        else s = m + 1;
    }
    return res;
}

int main(void) {
    
    input_data();

    cout << solve() << '\n';

    return 0;
}
