#include <string>
#include <vector>

using namespace std;

//DP - n일 때 경우 수 = (n-2)일 때 경우 수 + (n-1)일 때 경우 수 점화식을 활용
long long solution(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    
    long long route1 = 1;
    long long route2 = 2;
    for(int i = 2; i < n; i++){
        int tmp = route2%1234567; // 오버플로우 방지
        route2 = (route1 + route2)%1234567; // 오버플로우 방지
        route1 = tmp;
    }
    
    return route2;
}
