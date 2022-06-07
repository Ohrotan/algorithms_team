#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;
int dp[31];
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    if( n %2 ==1 ){
        cout <<"0\n";
        return 0;
    }
    dp[0] = 1;
    dp[2] = 3;
    dp[4] = 11;
    for(int i=6; i<=n; i+=2){
        dp[i] += dp[i-2] *3;
        //dp[4] ,dp[6] 일 때 2개씩? 추가됨.
        int idx = i-4;
        while(idx>=0){
            dp[i]+= dp[idx] *2;
            idx-=2;
        }
        // cout << i <<"  " << dp[i] <<endl;
    }
    cout <<dp[n] <<endl;
}