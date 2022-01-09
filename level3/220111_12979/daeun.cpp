#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0; // 최종 결과
    int s_wide = 2 * w + 1; // 한 기지국의 양 옆 고려한 전파 너비
    stations.push_back(n); // 마지막 기지국 ~ 맨끝 공백 연산을 위해 추가
    
    // 기지국 component를 반복하면서, 왼쪽 부터 공백인 아파트 거리를 구함
    // (아파트 공백 구간 / 양측 전파너비)를 올림한 값 = 필요 기지국 개수
    for(int i = 0; i < stations.size(); i++){
        int s_cur = stations[i] - w; // i번째 기지국의 전파 왼쪽 
        int s_pre = stations[i-1] + w; // i-1번째 기지국의 전파 오른쪽
        // 첫번째 기지국: 가장 왼쪽 부터의 공백 구간 구함
        if (i == 0){
            // 공백 구간 없음: 새로운 기지국 필요없으므로 continue
            if(s_cur <= 1) 
                continue;
            answer += (s_cur - 1) / s_wide;
            // 올림 처리
            if ((s_cur - 1) % s_wide != 0)
                answer++;
            continue;
        }
        // 마지막 기지국
        else if(i == stations.size()-1){
            // 예제 1처럼 마지막 기지국이 맨 끝에 있으면 continue (이전 반복문의 else문에서 이미 구했음)
            if(stations[i] == stations[i-1])
                continue;
            // 공백 구간 없음
            if(n <= s_pre)
                continue;
            answer += (n - s_pre) / s_wide;
            // 올림 처리
            if ((n - s_pre) % s_wide != 0)
                answer++;
            continue;
        }
        else{
            // 공백 구간 없음
            if(s_cur <= s_pre)
                continue;
            answer += (s_cur - s_pre -1) / s_wide;
            // 올림 처리
            if ((s_cur - s_pre - 1) % s_wide != 0)
                answer++;
        }
    }
    return answer;
}
