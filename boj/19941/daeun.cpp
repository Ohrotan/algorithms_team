#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int N, K;
string str;

int main(void) {
    cin >> N >> K;
    cin >> str;

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (str[i] != 'H') continue;

        int flag = 0;
        for (int j = i - K; j <= i + K; j++) {
            if (j < 0 || j >= N) continue;
            if (str[j] == 'P') { 
                cnt++; 
                str[j] = '-'; 
                break; 
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
