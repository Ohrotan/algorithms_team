// WRONG ANSWER
#include <iostream>
#include "vector"

int main() {
    long long a = 1002373400, b = 2, c = 1520023;
    // std::cin >> a >> b >> c;
    std::vector<int> history;
    int answer = -1;
    long long res = a;
    int loopCnt = 0;
    int resIdx = 0;
    history.push_back(res % c);
    for (int i = 0; i < b; ++i) {
        res = (res * res) % c;
        for (int j = 0; j < history.size(); ++j) {
            if (history[j] == res) {
                loopCnt = history.size() - j;
                resIdx = (b - j) % loopCnt + j;
                answer = history[resIdx];
                break;
            }
        }
        history.push_back(res);
        if (answer > 0) {
            break;
        }
    }
    std::cout << "ANSWER: " << ((answer > 0) ? answer : history.back()) << std::endl;
    return 0;
}
