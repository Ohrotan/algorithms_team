using namespace std;

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
