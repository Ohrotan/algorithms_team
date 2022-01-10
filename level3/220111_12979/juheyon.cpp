#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int now = 1; // 현재 기지국 위치
    int idx = 0; // stations의 인덱스 변수
    while (now <= n)
    {
        // 이미 설치되어있음.
        if (now >= stations[idx] - w && now <= stations[idx] + w)
        {
            now = stations[idx] + w;
            idx++;
        }
        // 설치 필요 
        else
        {
            now += 2 * w;
            answer++;
        }
        now++;
    }

    return answer;
}