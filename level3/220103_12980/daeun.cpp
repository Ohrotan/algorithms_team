#include <iostream>
using namespace std;
// 2배는 순간이동으로 ans에 건전지 사용량 추가가 없고
// 1칸 이동시에만 ans에 건전지 사용량 1추가

int solution(int n)
{
    int ans = 0;
    while(n != 0){
        if(n%2 == 1){
            ans += 1;
        }
        n /= 2;
    }
    return ans;
}
