#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_D 3000
#define MAX_N 30000

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
    int max_cnt;
    int cnt = 0;
    int prev_sushi_num;

    for (int i = 0; i < k; i++) {
        sushi_num = _data[i];
        if (!sushi[sushi_num]) cnt++;
        sushi[sushi_num]++;
        if (i == 0) prev_sushi_num = sushi_num; 
    }
    max_cnt = cnt;

    for (int i = 0; i < N-1; i++) {
        sushi[prev_sushi_num]--;
        if (!sushi[prev_sushi_num]) cnt--;
        idx1 = (idx1 + 1) % N;

        idx2 = (idx2 + 1) % N;
        sushi_num = _data[idx2];
        if (!sushi[sushi_num]) cnt++;
        sushi[sushi_num]++;
        
        prev_sushi_num = _data[idx1];

        int cnt_tmp;
        cnt_tmp = sushi[c] ? cnt : cnt + 1;
        max_cnt = max(cnt_tmp, max_cnt);

    }

    cout << max_cnt << "\n";

    return 0;
}
