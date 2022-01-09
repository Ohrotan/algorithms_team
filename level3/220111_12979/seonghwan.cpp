/*
    - 수행시간 : 0.01~0.12ms, 메모리 : 4.95~4.32MB
    - 맨 뒤 조건을 따져주는 코드를 추가로 넣기 싫어서 n + w + 1 부분에도 아파트가 있다고 생각하고 계산함.
    - for문을 통해 이 전 전파가 마지막으로 닿은 아파트와 다음 아파트가 맨 왼쪽에 전파한 곳의 아파트 사이의
      거리가 0 이하이면 넘어감
    - 그게 아니라면 2w + 1많큼 나눠서 몫많큼 더함(이게 설치한다는 뜻)
    - 나머지가 있다면 추가로 1개 더 설치 해 줘야함
*/
#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int beforeRadioWavePoint = 0;//이 전 기지국의 전파가 최대로 닿을 수 있는 아파트 넘버

    stations.push_back(n + w + 1);//n + 1까지 전파가 닿는 아파트가 뒤에 추가로 있다고 가정해야 덜 귀찮음

    for (int i = 0; i < stations.size(); i++) {
        if (stations.at(i) - w - 1 > beforeRadioWavePoint) {

            answer += ((stations.at(i) - w - 1) - (beforeRadioWavePoint)) / (2 * w + 1);

            if (((stations.at(i) - w - 1) - (beforeRadioWavePoint)) % (2 * w + 1) != 0) answer++;
            beforeRadioWavePoint = stations.at(i) + w;
        }
        beforeRadioWavePoint = stations.at(i) + w;
    }

    return answer;
}
