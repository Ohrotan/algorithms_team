using namespace std;
// n번칸에 도달하는 모든 경우의 수 = n-1칸에 도달하는 모든 경우의 수에서 1칸 뛰기한 경우 + n-2칸에 도달하는 모든 경우의 수에서 2칸 뛰기한 경우
// (a + b) % m = ((a % m) + (b % m)) % m

long long MOD = 1234567;

int arr[2001] = {0,};

int fib(int n) {
    if (arr[n] == 0) {
        arr[n] = fib(n-1) + fib(n-2);
        arr[n] %= MOD;
    }
    return arr[n];
}

long long solution(int n) {
    arr[1] = 1;
    arr[2] = 2;
    return fib(n)%MOD;
}
