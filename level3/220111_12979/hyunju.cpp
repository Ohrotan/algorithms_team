// 시간 효율 0.11ms, 메모리 효율 3.95MB
// "앞에서부터" 순차적으로 기지국을 가장 효율적인 위치에 설치
#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    int sIdx = 0;
    int i = 1+w;
    stations.push_back(200010001);  // 마지막 기지국이 n보다 작으면 루프가 끝나므로 편의를 위해 생성
    while (i <= n + w) {  // n+w는 다음 효율적인 기지국이 위치가 n을 넘어갈 수 있기 때문에 설정
        if (i < stations[sIdx]) {
            ++answer;
            i = i+2*w+1;
        } else {
            i = stations[sIdx]+2*w+1;  // 다음 기지국 위치 갱신
            ++sIdx;
        }
    }

    return answer;
}
