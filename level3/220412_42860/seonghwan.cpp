//테케 몇 개가 안맞는다;;;;

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;

    int minShift = name.length() - 1;
    int lastIdx = name.length() - 1;
    int firstA;
    int lastA;

    for (int i = 0; i < name.length(); i++) {
        answer += min((int)('Z' - name[i] + 1), (int)(name[i] - 'A'));

        if (name[i] == 'A') {
            firstA = i;
            lastA = i;

            while (true) {
                if (lastA + 1 <= lastIdx) {
                    if (name[lastA + 1] == 'A') {
                        lastA++;
                    }
                    else {
                        break;
                    }
                }
                else {
                    break;
                }
            }
            i = lastA;

            minShift = min(minShift, (firstA - 1) * 2 + (lastIdx - (lastA + 1) + 1));
            minShift = min(minShift, 2 * (lastIdx - (lastA + 1) + 1) + (firstA - 1));

        }

    }

    answer += minShift;

    return answer;
}