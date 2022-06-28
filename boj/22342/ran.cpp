#include <iostream>
#include <vector>
#include "math.h"

using namespace std;
int R, C;
vector<string> weights;
vector<vector<int>> outputs;

void findMaxInput(int r, int c) {
    for (int nr = max(r - 1, 0); (nr <= r + 1 && nr < R); ++nr) {
        outputs[r][c] = max(outputs[r][c], outputs[nr][c - 1]);
    }
    outputs[r][c] += weights[r][c] - '0';
}

void input() {
    cin >> R >> C;
    weights.assign(R, "");

    vector<int> tmp(C, 0);
    outputs.assign(R, tmp);

    for (int i = 0; i < R; ++i) {
        cin >> weights[i];
        outputs[i][0] = weights[i][0] - '0';
    }
}

int main() {
    input();

    for (int c = 1; c < C; ++c) {
        for (int r = 0; r < R; ++r) {
            findMaxInput(r, c);
        }
    }
    int res = 0;
    for (int i = 0; i < R; ++i) {
        res = max(res, outputs[i][C - 2]);
    }
    cout << res << endl;
}
