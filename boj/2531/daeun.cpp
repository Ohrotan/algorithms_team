#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_D 3001
#define MAX_N 30001

int N, d, k, c;
int sushi[MAX_D];
int _data[MAX_N];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> d >> k >> c;

    int sushi_num;
    for(int i = 0; i < N; i++) {
        cin >> sushi_num;
        _data[i] = sushi_num;
    }

    int idx1 = 0;
    int idx2 = k-1;
    int max_cnt = 0;
    int cnt = 0;

    for (int i = 0; i < k; i++) {
        sushi_num = _data[i];
        if (sushi[sushi_num] == 0) cnt++;
        sushi[sushi_num]++;
    }
    max_cnt = sushi[c] ? cnt : cnt + 1;

    while (idx1 < N) {
        sushi[_data[idx1]]--;
        if (sushi[_data[idx1]] == 0) cnt--;
        idx1++;

        idx2 = (idx2 + 1) % N;
        sushi_num = _data[idx2];
        if (sushi[sushi_num] == 0) cnt++;
        sushi[sushi_num]++;
        
        int cnt_tmp;
        cnt_tmp = sushi[c] ? cnt : cnt + 1;
        max_cnt = max(cnt_tmp, max_cnt);

    }

    cout << max_cnt << "\n";

    return 0;
}
