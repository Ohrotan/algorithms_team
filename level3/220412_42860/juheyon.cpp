/*
그리디로 풀었다가 
그리디로는 풀 수 없는 문제여서
정답 보고 풀었더니
이전 그리디 코드가 날라갔네......
*/

#include <algorithm>
#include <string>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.length();
    int turn = n - 1;
    for (int i = 0; i < n; i++) {
        if (name[i] - 'A' < 14) answer += name[i] - 'A';
        else answer += 'Z' - name[i] + 1;

        int ind = i + 1;
        while (ind < n && name[ind] == 'A') ind++;

        turn = min(turn, i + n - ind + min(i, n - ind));
    }

    answer += turn;
    return answer;
}