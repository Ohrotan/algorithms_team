#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    
    vector<int> v(n+1);
    if (n <= 2) {
        return n;
    }
    v[1] = 1;
    v[2] = 2;
    for (int i = 3; i <= n; ++i) {
        v[i] = v[i-1] + v[i-2];
        if (v[i] >= 1234567) {
            v[i] = v[i] % 1234567;    
        }
    }
    answer = v[n];
    return answer;
}
