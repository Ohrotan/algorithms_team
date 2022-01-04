// 경우의 수를 쌓아간다. - dp
// money의 종류를 늘리는식
// 한 종류의 money에서 i만큼 쌓인 경우의 수는 i-money만큼의 경우의 수다.
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;

    vector<int> v(n+1);
    v[0] = 1;
    for(int m : money) {
        for (int i = m; i <= n; i++) {
            v[i] += v[i-m];
            if (v[i] >= 1000000007) {
                v[i] = v[i] % 1000000007;
            }
        }
    }
    answer = v[n];
    
    return answer;
}
