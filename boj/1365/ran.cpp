#include <vector>
#include <iostream>

using namespace std;
int N;
vector<int> lis;

int findLowerBoundIndex(int num) {
    // lis는 증가수열로, 이미 정렬이 되어있으므로 이진탐색 이용해서 찾기
    int left = 0;
    int right = lis.size();
    int mid = 0;
    while (true) {
        mid = (left + right) / 2;
        if (mid == left) {
            return lis[mid] < num ? mid + 1 : mid;
        }
        if (lis[mid] < num) {
            left = mid;
        } else if (lis[mid] > num) {
            right = mid;
        } else {
            return mid;
        }
    }
}

int main() {
    int num = 0;
    scanf("%d", &N);
    lis.reserve(N); // 최장 증가 부분 수열, 미리 사이즈 확보
    lis.push_back(-1); // 35line에서 맨 첫 숫자와 비교를 위해서 -1 삽입
    for (int i = 0; i < N; ++i) {
        scanf("%d", &num);
        if (lis.back() < num) { // 최장 증가 수열의 마지막 숫자보다 크다면 수열에 추가
            lis.push_back(num);
        } else {
            // 마지막 숫자보다 작다면
            int lowerBoundId = findLowerBoundIndex(num); // lis에서 lower bound인 숫자의 인덱스 구하기
            lis[lowerBoundId] = num; // lower bound인 숫자를 num으로 교체해주기
            // num은 lowerBoundId 보다 뒤에 나온 숫자인데 왜 lis 배열의 앞으로 보내주는거지??하고 처음에 이해가 안 되었는데,
            // 이 방식은 기존 배열의 순서를 유지하여 어떤 숫자가 뽑혔는지가 중요한 것이 아님 -> 만약 그것을 알아야한다면 O(n^2)이 불가피할듯
            // 이 문제에선 최장 수열의 '길이'를 원하므로 lower bound인 숫자를 num으로 교체함
            // '길이'가 중요하기 때문에 실제 답을 구해가는 쪽은 36line의 push_back이 중요한 것
            // 그럼 lower bound는 왜 교체하냐?
            // 이건 one line DP 처럼 생각해야함,
            // 지금 lis 수열은 그 순서로서 의미를 가지는 것이 아님, 가장 긴 수열을 만들기 위한 계산판?이라고 생각해야함
            // 교체하는 자리(lowerBoundId)에서부터 새롭게 증가 수열을 시작했다고 생각할 수 있음
            // lis에서 lowerBoundId 이전은 나랑 이어질 수 있는 값들이지만 (순서상 앞이고, num보다 작은 값들이다)
            // 이후의 자리는 num 다음에 나오는 값들인 것이 아니라, num으로 교체되기 이전의 기록이 아직 남아있는 것이다. (그 기록이 최장일 수도 있으므로)
            // num이 lowerBoundId로 위치함으로 인해서 미래에 뒤의 값들도 반복적으로 교체되면서 결국 배열의 '길이'가 늘어날 수도 있다.

        }
    }
    cout << N - (lis.size() - 1); // 32line에서 '-1' 삽입한 것은 개수에서 뻬주기
    return 0;
}
