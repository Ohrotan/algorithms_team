#include <vector>

using namespace std;
const int DIV = 1000000007;

vector<vector<int>> dp;
vector<int> coins;
int money;

int totalCase(int money, vector<int> coins);
int dpOneLine();
int dpUp();
int dpDown(int coinId, int tmoney);
int dpSol();


int solution(int n, vector<int> _coins) {
    money = n;
    coins = _coins;
    // coins sort 필요한데 안해도 통과되네, 마지막에 안 나눠도 통과되네..ㅎ
    
    // return totalCase(n, coins); // 풀이법 1. 정확성 O, 효율 실패
    // return dpSol() % DIV; // 풀이법 2. 효율성 17ms 
    return dpOneLine(); // 퓰이법 3. 효율성 4.5ms
}

int dpOneLine() {
    vector<int> dp1;
    dp1.assign(money+1, 0);
    for(int i = 0; i*coins[0] <= money; ++i) {
        dp1[coins[0]*i] = 1;
    }
    
    for (int i = 1; i < coins.size(); ++i) {
        for (int j = 1; j <= money; ++j) {
            if (j >= coins[i]) {
                dp1[j] += dp1[j-coins[i]];
            }
        }
    }
    return dp1[money];
}

int dpSol() {
    for (int i = 0; i < coins.size(); ++i){
        vector<int> tmp;
        tmp.assign(money+1, -1);
        tmp[0] = 1;
        dp.push_back(tmp);
    }
    dp[0].assign(money+1, 0);
    for(int i = 0; i*coins[0] <= money; ++i) {
        dp[0][coins[0]*i] = 1;
    }
    // return dpUp(); // 풀이법 2-1. 효율성 평균 17.5ms
    return dpDown(coins.size()-1, money); // 풀이법 2-2. 효율성 평균 16.5ms
}

int dpUp() {
    for(int i = 1; i < coins.size(); ++i) {
        for(int j = 1; j <= money; ++j) {
            dp[i][j] = dp[i-1][j];
            if (j >= coins[i]) {
                dp[i][j] += dp[i][j-coins[i]];
            } 
        }
    }
    return dp[coins.size()-1][money];
}

int dpDown(int coinId, int tmoney) {
    if (tmoney < 0) return 0;
    if (dp[coinId][tmoney] == -1) {
        dp[coinId][tmoney] = dpDown(coinId-1, tmoney) + dpDown(coinId, tmoney - coins[coinId]);
    }
    return dp[coinId][tmoney];
}

int totalCase(int money, vector<int> coins) {
    int coinCnt = coins.size();
    
    int res = 0;
    int nmoney = money;
    int coin = coins.back(); 
    coins.pop_back();
    if (coins.size() == 0) {
        return (money % coin == 0); // 남은 코인으로 나눠지면 1을 리턴
    }
    while (1) {
        res += totalCase(nmoney, coins);
        nmoney -= coin;
        if (nmoney < 0) break;
        if (nmoney == 0) {
            res++;
            break;
        }
    }
    return res;
}

