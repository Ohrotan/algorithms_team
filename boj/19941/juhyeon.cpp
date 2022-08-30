
#include <iostream>
#include <vector>

using namespace std;
int N, K;
int arr[20001];
int ans;
/*
가장 먼 왼쪽에 있dd
는 햄버거부터 먹어야한다.
내가 못 먹으면 내 다음사람도 못먹을 것이고,
내가 그걸 안먹으면 다음사람과는 거리가 더 멀어지기 때문이다.

*/
int main()
{
    string buger;
    cin >> N >> K;
    cin >> buger;
    for (int i = 0; i < N; i++)
    {
        if (buger[i] == 'H'){
            arr[i] = 0;
        }
        else{
            arr[i] = 1;
        }
    }
    for (int i = 0; i < N; i++)
    {
        //햄버거는 지나가기
        if(arr[i] != 1) continue;
        for(int j = max(0,i-K); j<=min(N-1,i+K); j++){
            if(arr[j] ==0){
                //햄버거 먹었으니 바꿔주기
                arr[j] = -1;
                ans++;
                break;
            }

        }
    }
    cout <<ans <<endl;

    return 0;
}
