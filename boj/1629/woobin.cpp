#include <iostream>
#include <cmath>
using namespace std;

long long A, B, C;
long long answer;

long long solution(int number, int count) {
	if (count == 0) {
	    return 1;
	} else if (count == 1) {
	    return number % C;
	}
	long long temp = solution(number, count / 2);
	long long result = temp * temp % C;
	if (count % 2 == 1) {
	    result = result * number % C;
	}
	
	return result;
}

int main() {
    cin >> A >> B >> C;
	answer = solution(A, B);
	cout << answer << "\n";
	return 0;
}
