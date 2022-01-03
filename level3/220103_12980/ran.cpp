using namespace std;

int solution(int n)
{
    int cnt = 1; // 처음 한칸은 무조건 가야함
    while (n > 1) { // 거꾸로 가면서 홀수인 칸에서는 한칸 점프로 이동
        if (n % 2) {
            cnt++;
            n--;
        }
        n /= 2;
    }

    return cnt;
}
