#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <string>
#include <cmath>
#include <vector>
#define MAX_N 10

using namespace std;

int N;
unordered_map<char, int> m; // 알파벳 숫자 표기  ex: { A : 9, B : 8 }
int cnt = 9;
unordered_map<char, int> num; // 자릿수 ex: { A : 10000, B : 100}
vector<char> _strcul[MAX_N];

// 2
// GCF
// ACDEB
int main(void) {
    string s;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s;
        int d = s.size();
        for (auto x : s) {
            num[x] += pow(10, d);
            d--;
            _strcul[i].push_back(x);
        }
    }

    // for (auto x: num) {
    //     printf("num[%c] = %d\n", x.first, x.second);
    // }
    // num[A] = 100000
    // num[B] = 10
    // num[C] = 10100
    // num[D] = 1000
    // num[E] = 100
    // num[F] = 10
    // num[G] = 1000

    while (!num.empty()) {
        int max = 0;
        char max_char;
        for (auto it = num.begin(); it != num.end(); ++it) {
            if (it->second > max) {
                max = it->second;
                max_char = it->first;
            }
        }
        m[max_char] = cnt--;
        num.erase(max_char);
    }

    // for (auto x: m) {
    //     printf("map[%c] = %d\n", x.first, x.second);
    // }
    // map[F] = 3
    // map[B] = 4
    // map[E] = 5
    // map[G] = 6
    // map[D] = 7
    // map[C] = 8
    // map[A] = 9

    int total_sum = 0;
    for (int i = 0; i < N; i++) {
        int num = 0;
        int d = 1;
        while (!_strcul[i].empty()) {
            char a = _strcul[i].back();
            _strcul[i].pop_back();

            num += m[a] * d;
            d *= 10;
        }
        total_sum += num;
        // printf("num: %d\n", num);
    }

    printf("%d\n", total_sum);
    return 0;
}
