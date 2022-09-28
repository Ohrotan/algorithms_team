#include <iostream>
#include "vector"
#include "algorithm"
#include "limits.h"

using namespace std;
int N, M, tmp, answer = INT_MAX;
std::vector<int> arr;
int solve() {
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int res = arr[j] - arr[i];
            if (res == M) {
                return M;
            } else if (res > M) {
                answer = min(answer, res);
                break;
            }
        }
    }
    return answer;
}
int main() {
    std::cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        std::cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());

    std::cout << solve() << std::endl;
    return 0;
}
