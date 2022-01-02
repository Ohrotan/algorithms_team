int solution(int n)
{
    int ans = 1;
    while (n > 1) {
        if (n % 2 != 0) ans++;
        n /= 2;
    }
    return ans;
}