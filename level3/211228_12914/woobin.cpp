#include <string>
#include <vector>
#define DIVI 1234567
using namespace std;

long long solution(int n) {
    long long dp[2001] = {0,};
    dp[0] = 1; dp[1] = 2;
    
    // 피보나치 처럼 규칙이 있음
    // 안나눠줘서 에러났는데 피보나치 값이 그렇게 큰가??
    for(int i = 2; i < n; i++) {
        dp[i] = (dp[i - 1] % DIVI) + (dp[i - 2] % DIVI);
    }
    
    return dp[n-1] % DIVI;
}

