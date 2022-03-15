#include <iostream>
#include <algorithm>

using namespace std;

int L[100001];
int N;

int main(){
    cin >> N;
    int here;
    int len = 0;
    for(int i=1; i<=N; ++i){
        cin >> here;
        auto pos = lower_bound(L+1, L + len +1, here);
        *pos = here;
        if(pos == L + len + 1)
            len++;
    }
    cout << N-len;

    return 0;
}