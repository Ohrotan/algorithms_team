// +1, x2로 K의 최적이 될 수 있도록 구현. (뒤로 가기 없음)
// bfs로 풀었는데, 메모리 초과/시간 초과가 나온다. 
// 10억 메모리의 DP도 마찬가지로 메모리 초과/시간 초과가 나온다.
// 거꾸로 n에서 0으로 가는 방식으로 구현 필요.
// 중요한 개념은... 최대한 나누기를 수행하고 나눌 수 없을 때 뺄셈을 하는 것이 무조건 유리하다.
// 짝수일 때 뺄셈을 2번 수행하면 비효율적이다.
// 예를 들어, A가 짝수일 때
// 나누기 최대한 수행: (A+2) -> (A/2+1) -> (A/2)
// 뺄셈 먼저 수행: (A+2) -> (A+1) -> (A) -> (A/2)
using namespace std;

int solution(int n)
{
    int ans = 0;
    while (n > 0) {
        ans += n % 2;
        n /= 2;
    }
    return ans;
}
