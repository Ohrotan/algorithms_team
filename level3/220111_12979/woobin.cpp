#include <iostream>
#include <vector>
using namespace std;

// TC 2개 틀리는데 이유 모르겠음

int calcNumOfStation(int start, int end, int coverArea) {
    // 오른편 기지국의 왼쪽 끝부분이 왼편 기지국의 오른쪽 끝부분보다 index가 크면 빈 곳은 없음
    int length = end - start;
    if(length <= 0) {
        return 0;
    }
    
    // 빈 곳 영역이 새로지을 기지국에 이 커버하는 범위에 딱 맞으면 몫, 아니면 몫 + 1
    return ((length % coverArea) == 0) ? (length / coverArea) : ((length / coverArea) + 1);
}

int solution(int n, vector<int> stations, int w){
    // coverArea = 단일 기지국이 커버하는 영역 수, size = 기지국 개수
    const int coverArea = 2 * w + 1;
    const int size = stations.size();
    int answer = 0;
    
    // 0번째 부터 첫번재 기지국 사이에 있는 영역 계산
    answer += calcNumOfStation(0, stations.at(0) - 1 - w, coverArea);
    
    // 맨처음, 마지막 기지국 사이에 있는 영역 계산
    for(int idx = 1; idx < size; idx++) {
        int end = stations.at(idx) - 1 - w;
        int start = stations.at(idx - 1) + w;
        answer += calcNumOfStation(start, end, coverArea);
    }
    
    // 마지막 기지국과 끝에 있는 영역 계산
    answer += calcNumOfStation(stations.at(size - 1) + 1 + w, n, coverArea);
    
    return answer;
}
