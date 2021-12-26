/*
    실행시간 : 0.01~0.02ms, 메모리 : 3.66MB~4.58MB
    피보나치, DP사용
    1234567로 나눈 나머지로 계산이 필요한 시점(임계점) = i-1과 i-2번째 모두 1234567로 나눈 몫이 1 이상일 때 i, i-1, i-2 위치에 있는 세 수 모두 나머지를 반환
    답에도 1234567를 나눈 나머지로 해 줘야 위에서 말한 임계점에서 계산 안된 값들에 대해 오류가 안남
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int n) {
    long long map[2001];

    for (int i = 1; i <= n; i++)
        map[i] = 0;//초기화

    map[1] = 1; map[2] = 2;
    if (n == 1) return map[1]; if (n == 2) return map[2];//1이나 2일때

    for (int i = 3; i <= n; i++) {//3이상일 때
        map[i] = map[i - 1] + map[i - 2];
        if (map[i - 1] / 1234567 >= 1 && map[i - 2] / 1234567 >= 1) {//i-1, i-2 모두 몫이 1 이상일때
            map[i] %= 1234567; map[i - 1] %= 1234567; map[i - 2] %= 1234567;//세 값 모두 나머지를 넣어줌
        }
    }

    return map[n] % 1234567;//위에서 20번째 줄에 걸리지 않는 애들 중에 몫이 1이 넘는 애들이 있으므로 여기도 나눠줘야함
}