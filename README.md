# algorithms_team
[스터디 내용](#study)  
[21.12.07 - 단체사진 찍기 (DFS, Back Tracking, Permutation)](#211207)  
[21.12.14 - 리틀 프렌즈 사천성](#211214)  
[21.12.21 - 디스크 컨트롤러](#211221)  
[21.12.28 - 멀리 뛰기](#211228)  
[22.01.04 - 거스름돈, 점프와 순간이동](#220104)  
[22.01.11 - 기지국 설치](#220111)


## 문제목록

| 번호 | 날짜     | 문제                                                    |
| ---- | -------- | ------------------------------------------------------- |
| 1    | 21.12.07 | https://programmers.co.kr/learn/courses/30/lessons/1835 |
| 2    | 21.12.14 | https://programmers.co.kr/learn/courses/30/lessons/1836 |
| 3    | 21.12.21 | https://programmers.co.kr/learn/courses/30/lessons/42627|
| 4    | 21.12.28 | https://programmers.co.kr/learn/courses/30/lessons/12914|
| 5    | 22.01.04 | https://programmers.co.kr/learn/courses/30/lessons/12907|
| 6    | 22.01.04 | https://programmers.co.kr/learn/courses/30/lessons/12980|
| 7    | 22.01.11 | https://programmers.co.kr/learn/courses/30/lessons/12979|
| 8    | 22.01.11 | https://programmers.co.kr/learn/courses/30/lessons/87391|


## 진행 규칙

- 월요일 밤까지 코드 업로드
- 화요일 21시에 webex 모임
- 업로드 경로 level?/날짜_문제번호/이름.cpp
- git push 는 master로
- 리더 순번: 조란-변성환-이다은-이현주-박주현-진우빈

## 진행 순서

1. 리더가 풀이법 설명
2. 리더가 시간/메모리/코드 단축할 수 있는 다른 사람 코드 소개
3. 다같이 좋은 방법 소개 or 궁금한 부분 묻기
4. 다음 문제 정하고 끝~

## 리더 사전 준비

1. 리더가 다른 사람 코드 다 읽기
2. 멤버들 풀이법 정리 (걸리는 시간, 메모리 비교, 장단점 비교)
3. 새로운 풀이법 찾기 (있는 경우에)
4. 시간/메모리/코드 단축할 수 있는 코드 tip 정리
5. webex 방 만들기


<a name="study"/>

## 스터디 내용

<a name="211207"/>

### 21.12.07 - 단체사진 찍기 (DFS, Back Tracking, Permutation)

| 구분   | 내용                                                    |
| ------ | ------------------------------------------------------- |
| 날짜   | 21.12.07 21:00                                          |
| 참석자 | 변성환, 이다은, 이현주, 조란                            |
| 리더   | 조란                                                    |
| 문제   | https://programmers.co.kr/learn/courses/30/lessons/1835 |
| 풀이  | level2/211207_1835|



사용 개념: DFS, Back Tracking, Permutation

사용이유: 

가능한 모든 경우의 수를 구하는 것이므로 전체탐색 필요

조건이 있으므로 조건에 해당하지 않으면 미리 가지치기 

순서가 있는 모든 경우의 수 이기 때문에 stdlibrary의 permutation 사용 가능 -> n이 적을 때는 코드 구현이 쉬움, n이 커지면 시간 복잡도 문제가 생김



수행 시간: 230 ~ 7500ms (프로그래머스 제출 기준)

메모리 사용: 4.1~ 4.3Mb



참고 링크:

https://soom-soom.tistory.com/m/101



#### Tips!

- 함수 인자보다 전역변수 사용 추천
- int friends_idx[8] = {-1,}; 이 문법은 0으로 초기화할 때만 가능
- vector<char> -> string 사용 가능, string에서 제공하는 메소드가 더 많아서 편리
- vector<T> a -> a.at(0) == a[0] (동작이 같은데 runtime error message가 다르게 올 수 있음)
- for문에서 continue 사용
- std::abs() 절댓값 구하기
- std::string::find(char), std::string::find(string) -> 첫번째 찾는 문자/문자열의 position 반환, 없으면 string::npos 반환
- unordered_map<T,V> -> O(n)으로 찾기 좋음


<a name="211214"/>

### 21.12.14 - 리틀 프렌즈 사천성

| 구분   | 내용                                                    |
| ------ | ------------------------------------------------------- |
| 날짜   | 21.12.14 21:00                                          |
| 참석자 | 박주현, 변성환, 이다은, 이현주, 조란                    |
| 리더   | 변성환                                                  |
| 문제   | https://programmers.co.kr/learn/courses/30/lessons/42627 |
|   | level3/211214_1836|

<다은>
사용개념 : DFS(알파벳 조합), BFS(알파벳 매칭)
시간 : 2158ms
메모리 : 4.26MB

<현주>
사용개념 : 그리디, hash table, 지각
시간 : 11ms
메모리 : 4.32MB

<주현>
사용개념 : BFS
시간 : 245ms
메모리 : 4.32MB

<성환>
사용개념 : 조건에 맞는 것만 날구현
시간 : 1.66ms
메모리 : 4.21MB

<외 1명>
사용개념 : 조건에 맞는 것만 날구현
시간 : 1.44ms
메모리 : 4.32MB

수행 시간: 230 ~ 7500ms (프로그래머스 제출 기준)

메모리 사용: 4.1~ 4.3Mb



참고 링크:

https://blog.naver.com/yoochansong/222089528785(unordered_map, ordered_map)



#### Tips!

- 조건이 까다롭지 않아서 조건을 만족하는 경우만 따져봐도 될듯
- unordered_map 애용하기(현주 나이스)
- emplace_back
- string compare : 맞으면 0(false), 틀리면 -1
  "asd" == "asd" : 맞으면 1(true), 틀리면 0(false)
  
  
<a name="211221"/>

### 21.12.21 - 디스크 컨트롤러

| 구분   | 내용                                                    |
| ------ | ------------------------------------------------------- |
| 날짜   | 21.12.21 21:00                                          |
| 참석자 | 박주현, 변성환, 이다은, 이현주, 조란                    |
| 리더   | 이다은                                                  |
| 문제   | https://programmers.co.kr/learn/courses/30/lessons/1836 |
|   | level3/211221_1836|

priority_queue : 우선순위 큐, 내부적으로는 힙과 비슷하게 동작

SJF(Shortest job first)

현재시각 기준 이전 에 도착한 job 중 제일 짧은 것 먼저 삽입 -> 최소힙에서 root pop

없으면 그 다음 Job



<다은> 사용개념 : job 정렬, priority_queue(최소힙), !빈 Pq 조건 while문 안에 반복

<현주> 사용개념 : job 정렬, priority_queue(최소힙), !빈 Pq 조건 while문 안에 반복, 들어온 시간의 합 - 끝난시간의 합

<란> 사용개념 : job 정렬, priority_queue(최소힙), job_idx 대신 jobs vector를 지움

<주현, 우빈> 사용개념 : job 정렬, priority_queue(최소힙)

<성환> 사용개념 : job 정렬, priority_queue(최소힙)

수행 시간: 0.01ms ~ 0.46ms

메모리: 3.67MB ~ 4.33MB

#### Tips!

JOB 구조체/2차원 벡터의 특정 속성을 가지고 힙을 구성할 때

```c++
struct JOB{
    int t_start; // 작업 요청 시점
    int t_exe; // 작업 소요 시간
};

// 작업 소요 시간 기준의 최소 힙
struct cmp{
    bool operator()(JOB a, JOB b){
        return a.t_exe > b.t_exe;
    }
};
/*
연산자를 오버로딩 - 우빈's
bool operator<(Request a, Request b) {
        return a.time > b.time;
}
*/

std::priority_queue<JOB, vector<JOB>, cmp> // 자료형 JOB, 컨테이너 vector, 사용자 정의 비교연산자 cmp
//std::priority_queue<vector<int>, vector<vector<int>>, cmp> diskQueue;
```

- 최대힙: priority_queue<T> max_heap;
- 최소힙: priority_queue<T, vector<T>, greater<T> > min_heap;
- Sort()의 디폴트는 오름차순 (배열이라면 각 인자 자리마다도 오름차순 정렬해줌)

  <a name="211228"/>
  
### 21.12.28 - 멀리 뛰기

| 구분   | 내용                                                    |
| ------ | ------------------------------------------------------- |
| 날짜   | 21.12.28 21:00                                          |
| 참석자 | 박주현, 변성환, 이다은, 진우빈, 조란                      |
| 리더   | 이현주                                                  |
| 문제   | https://programmers.co.kr/learn/courses/30/lessons/12914|
|   | level3/211228_12914|

<다은, 현주, 주현, 우빈, 성환> 사용개념 : Dynamic Programming, 칸의 수가 작은 것 부터 큰 순으로 값을 구해나감.

<란> 사용개념 : 재귀+메모이제이션, 목표 칸 수를 기준으로 재귀로 쌓아 나감.

수행 시간: 0.01ms ~ 0.06ms

메모리: 3.67MB ~ 4.33MB

#### Tips!

큰 수가 답이 되는 경우 종종 문제에서 나머지 연산을 한 결과값을 도출하라고 하는 경우가 있다.  
반복문에서 아래와 같이 구성하는 것과  
if (v[i] >= 1234567) {  
v[i] = v[i] % 1234567;  
}  
if 문을 제외하는 것과 속도는 동일하다. 나머지 연산 자체에서 몫이 0인 경우를 나눠 연산이 빠를 것으로 예상함.  

나머지 연산의 결합 법칙  
(A + B) % p = ((A % p) + (B % p)) % p  
(A * B) % p = ((A % p) * (B % p)) % p  
(A - B) % p = ((A % p) - (B % p) + p) % p  

위 문제에서는 값을 더하고 최종적으로 나머지 연산 한번만 수행하면 된다.


<a name="220104"/>
  
### 22.01.04 - 점프와 순간이동

| 구분   | 내용                                                    |
| ------ | ------------------------------------------------------- |
| 날짜   | 22.01.04 21:00                                          |
| 참석자 | 박주현, 변성환, 이다은, 진우빈, 조란                      |
| 리더   | 박주현                                                |
| 문제   | https://programmers.co.kr/learn/courses/30/lessons/12980|
|   | level3/22010312980|

칸까지 갈때, 건전지 사용량을 최소화 시켜야하는 문제. 
모두의 풀이가 초기값과, while문의 범위를 제외하곤 똑같음
<란, 성환, 우빈> 초기값 1, while > 1
<다은, 주현> 초기값 0, while > 0

수행 시간: 0.01ms
메모리: 3.62MB ~ 4.33MB

#### Tips!
  n--; << 어차피 이후에 /2로 버려주기 때문에 없어도 됨.
  

### 22.01.04 - 거스름돈 

| 구분   | 내용                                                    |
| ------ | ------------------------------------------------------- |
| 날짜   | 22.01.04 21:00                                          |
| 참석자 | 박주현, 변성환, 이다은, 진우빈, 조란                      |
| 리더   | 박주현                                                |
| 문제   | https://programmers.co.kr/learn/courses/30/lessons/12907|
|   | level3/22010312907|


수행 시간: 0.02ms~ 4.24ms
메모리: 3.62MB ~ 4.75MB

#### Tips!
  이차원 배열로 이해하고, 일차원 배열로 줄여가는게 좋음!

