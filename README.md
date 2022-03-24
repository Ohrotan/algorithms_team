# algorithms_team
[스터디 내용](#study)  
[21.12.07 - 단체사진 찍기 (DFS, Back Tracking, Permutation)](#211207)  
[21.12.14 - 리틀 프렌즈 사천성](#211214)  
[21.12.21 - 디스크 컨트롤러](#211221)  
[21.12.28 - 멀리 뛰기](#211228)  
[22.01.04 - 거스름돈, 점프와 순간이동](#220104)  
[22.01.11 - 기지국 설치](#220111)  
[22.01.18 - 경주로 건설](#220118)  
[22.01.25 - 파괴되지 않은 건물](#220125)  
[22.02.08 - 양과 늑대](#220208)   
[22.02.15 - 양궁대회](#220215)   
[22.02.22 - 스도쿠](#220222)   
[22.03.22 - 평범한 배낭](#220322)   
## 문제목록

| 번호   | 날짜       | 문제                                       |
| ---- | -------- | ---------------------------------------- |
| 1    | 21.12.07 | https://programmers.co.kr/learn/courses/30/lessons/1835 |
| 2    | 21.12.14 | https://programmers.co.kr/learn/courses/30/lessons/1836 |
| 3    | 21.12.21 | https://programmers.co.kr/learn/courses/30/lessons/42627 |
| 4    | 21.12.28 | https://programmers.co.kr/learn/courses/30/lessons/12914 |
| 5    | 22.01.04 | https://programmers.co.kr/learn/courses/30/lessons/12907 |
| 6    | 22.01.04 | https://programmers.co.kr/learn/courses/30/lessons/12980 |
| 7    | 22.01.11 | https://programmers.co.kr/learn/courses/30/lessons/12979 |
| 8    | 22.01.11 | https://programmers.co.kr/learn/courses/30/lessons/87391 |
| 9    | 22.01.18 | https://programmers.co.kr/learn/courses/30/lessons/43162<br />https://programmers.co.kr/learn/courses/30/lessons/67259 |
| 10   | 22.01.25 | https://programmers.co.kr/learn/courses/30/lessons/92344 |
| 11   | 22.02.08 | https://programmers.co.kr/learn/courses/30/lessons/92343 |
| 12   | 22.02.15 | https://programmers.co.kr/learn/courses/30/lessons/92342 |
| 13   | 22.02.22 | https://www.acmicpc.net/problem/2580 |
| 17   | 22.03.22 | https://www.acmicpc.net/problem/12865|



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

| 구분   | 내용                                       |
| ---- | ---------------------------------------- |
| 날짜   | 21.12.07 21:00                           |
| 참석자  | 변성환, 이다은, 이현주, 조란                        |
| 리더   | 조란                                       |
| 문제   | https://programmers.co.kr/learn/courses/30/lessons/1835 |
| 풀이   | level2/211207_1835                       |



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

| 구분   | 내용                                       |
| ---- | ---------------------------------------- |
| 날짜   | 21.12.14 21:00                           |
| 참석자  | 박주현, 변성환, 이다은, 이현주, 조란                   |
| 리더   | 변성환                                      |
| 문제   | https://programmers.co.kr/learn/courses/30/lessons/42627 |
|      | level3/211214_1836                       |

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

  ​
<a name="211221"/>

### 21.12.21 - 디스크 컨트롤러

| 구분   | 내용                                       |
| ---- | ---------------------------------------- |
| 날짜   | 21.12.21 21:00                           |
| 참석자  | 박주현, 변성환, 이다은, 이현주, 조란                   |
| 리더   | 이다은                                      |
| 문제   | https://programmers.co.kr/learn/courses/30/lessons/1836 |
|      | level3/211221_1836                       |

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

| 구분   | 내용                                       |
| ---- | ---------------------------------------- |
| 날짜   | 21.12.28 21:00                           |
| 참석자  | 박주현, 변성환, 이다은, 진우빈, 조란                   |
| 리더   | 이현주                                      |
| 문제   | https://programmers.co.kr/learn/courses/30/lessons/12914 |
|      | level3/211228_12914                      |

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

| 구분   | 내용                                       |
| ---- | ---------------------------------------- |
| 날짜   | 22.01.04 21:00                           |
| 참석자  | 박주현, 변성환, 이다은, 진우빈, 조란                   |
| 리더   | 박주현                                      |
| 문제   | https://programmers.co.kr/learn/courses/30/lessons/12980 |
|      | level3/22010312980                       |

칸까지 갈때, 건전지 사용량을 최소화 시켜야하는 문제. 
모두의 풀이가 초기값과, while문의 범위를 제외하곤 똑같음
<란, 성환, 우빈> 초기값 1, while > 1
<다은, 주현> 초기값 0, while > 0

수행 시간: 0.01ms
메모리: 3.62MB ~ 4.33MB

#### Tips!
  n--; << 어차피 이후에 /2로 버려주기 때문에 없어도 됨.


### 22.01.11 - 기지국 설치

| 구분   | 내용                                       |
| ---- | ---------------------------------------- |
| 날짜   | 22.01.11 21:00                           |
| 참석자  | 박주현, 변성환, 이다은, 진우빈, 조란, 이현주              |
| 리더   | 진우빈                                      |
| 문제   | https://programmers.co.kr/learn/courses/30/lessons/12979 |
|      | level3/22011112979                       |

- 설치해야할 기지국의 갯수를 구하는 문제 --> 경우의 수를 구하는 것이 아니기 때문에 완전 탐색할 필요가 없다.
- 왼쪽 기지국의 오른쪽 커버 범위 > 오른쪽 기지국의 왼쪽 커버 범위 --> 빈 곳이 없기 때문에 count 계산 할 필요가 없다.  

- <란, 성환> 기지국 vector의 앞과 뒤에 가상의 기지국을 넣어주어서 반복문 한번에 끝냄 
- <현주, 주현> 몫, 나머지 연산을 사용하지 않고 현재 자기위치를 처음부터 세어 나가면서 계산 (매우 직관적임)
- <우빈, 다은> 처음부터 첫 번째 기지국, 기지국과 기지국 사이, 마지막 기지국과 맨 끝 이렇게 3가지 경우에 대해 count 계산


#### Tips!
- 웬만하면 반복문 한번에 코드를 구성하는 것이 가독성이 좋은 것 같다...
- 삼항연산자를 사용하는 것이 효율과 가독성 측면에서 좋을 수 있음
- if 문만 있는 것에선 효율 면에서 별 차이 없으나, if else 가 같이 있을 때는 삼항연산자가 효율이 더 좋음
- https://blackseven.tistory.com/entry/%EC%82%BC%ED%95%AD-%EC%97%B0%EC%82%B0%EC%9E%90%EC%A1%B0%EA%B1%B4-%EC%97%B0%EC%82%B0%EC%9E%90 참조

  ​
수행 시간: 0.02ms~ 4.24ms

메모리: 3.62MB ~ 4.75MB

<a name="220118"/>

  ### 22.01.18 - 공 이동 시뮬레이션

| 구분   | 내용                                       |
| ---- | ---------------------------------------- |
| 날짜   | 22.01.18 21:00                           |
| 참석자  | 박주현, 변성환, 이다은, 진우빈, 조란, 이현주              |
| 리더   | 조란                                       |
| 문제   | https://programmers.co.kr/learn/courses/30/lessons/87391 |
|      | level3/22011887391                       |

- 행열의 수가 각각 최대 10억, 명령은 최대 20만이므로 시간복잡도는 O(n)이어야함
- 행과 열은 서로 영향을 끼치지 않으므로 따로 생각
- 이동이 불가능한 명령어도 있음을 고려해야함
- <주현, 성환, 다은, 우빈, 란>
  - 도착점으로부터 명령을 거꾸로, 반대로 수행하며 가능한 시작점의 범위를 찾음
  - 가능한 시작범위의 start좌표, end좌표를 두고 명령을 수행하며 좌표값 변경
- <현주> 
  - 전체 칸에 대해서 가능한 시작점이라는 가정으로 시작
  - 명령을 순차적으로 수행하며 불가능한 시작점들을 제거
  - 각 행열의 끝인덱스에 가능한 경우의 수를 저장
  - 마지막에 도착점에 가능한 경우의 수가 정답 (행열의 인덱스의 곱)

#### Tips!
- 상수 정의 'enum class, #define LEFT 1'

- 적은 return문의 사용은 잠재적 오류를 줄이고 가독성을 좋게함

  ​

  
  
  <a name="220125"/>
  
### 22.01.25 - 경주로 건설

| 구분   | 내용                                       |
| ---- | ---------------------------------------- |
| 날짜   | 22.01.25 21:00                           |
| 참석자  | 박주현, 변성환, 이다은, 진우빈, 조란, 이현주              |
| 리더   | 변성환                                       |
| 문제   | https://programmers.co.kr/learn/courses/30/lessons/67259 |
|      | level3/22011887391                       |

  상하좌우로 가는 비용이 다르기 때문에 각 지점에서 상하좌우로 들어왔을 때의 최저비용 -> 그 다음에도 최저비용이 이어질 것인지에 대한 예외케이스를 생각 해 줘야 함.
  
  
  <현주>
    - 실행시간 : 0.01ms~81.44ms, 메모리 : 3.63MB~4.27MB
    - dfs + 3차원 배열(x, y, dir)
    
  <주현>
    - bfs + 2차원 배열(x, y)
    
  <조란>
    - 실행시간 : 0.01ms~0.23ms, 메모리 : 3.63MB~4.35MB
    - bfs + 3차원 벡터(x, y, dir)
    
  <성환>
    - 실행시간 : 0.01ms~0.48ms, 메모리 : 3.67MB~4.35MB
    - bfs + 3차원 배열(y, x, dir)
    
  <우빈>
    - dfs + 2차원 배열(x, y)
    


#### Tips!
- 구현하기 전 예외적인 케이스에 대해 최대한 생각
- 직선을 우선적으로 탐색 -> 시간효율 증대
- vector.assign(https://modoocode.com/183)
- 2차원 방향관련 문제에서의 abs 활용한 반대방향 판별여부

    <a name="220208"/>
    
### 22.02.08 - 파괴되지않은 건물

| 구분   | 내용                                                     |
| ------ | -------------------------------------------------------- |
| 날짜   | 22.02.08 21:00                                           |
| 참석자 | 박주현, 변성환, 이다은, 진우빈, 조란                     |
| 리더   | 이다은                                                   |
| 문제   | https://programmers.co.kr/learn/courses/30/lessons/92344 |
|        | level3/220215_92343                                      |

누적합 배열 생성

특정 구간의 누적합 배열에 k 값 추가

ㄴex) 0~2 구간에 k 만큼의 영향을 준다면, 시작점 0에 k 더함, 끝점 2 + 1 위치에 -k 더함

i번째 배열과 i+1번 째 배열 행, 열 각각 누적합 연산

board 2차원 배열과 각 자리 더하기



<주현> - 실행시간: 0.01 ~ 29.08ms

<조란> - 실행시간 : 0.01 ~ 545.07ms - 세로 부분은 각 배열에 더하고, 가로 부분은 누적합

<성환> - 실행시간 : 0.01 ~ 29.00ms - 왼쪽 위 좌표에서 오른쪽 끝, 왼쪽 끝까지 k만큼 선 공격 후 벗어난 범위 치유

<우빈> - 실행시간: 0.01 ~ 30.17ms

<다은> - 실행시간: 2.04 ~ 29.68ms

#### Tips!

- 누적합 개념과 문제풀이 설명 블로그

  https://kimjingo.tistory.com/155
  
  <a name="220215"/>
  
### 22.02.15 - 양과 늑대

| 구분   | 내용                                                     |
| ------ | -------------------------------------------------------- |
| 날짜   | 22.02.15 21:00                                           |
| 참석자 | 변성환, 이다은, 조란                     |
| 리더   | 이현주                                                   |
| 문제   | https://programmers.co.kr/learn/courses/30/lessons/92343 |
|        | level3/220215_92343                                      |
  

<조란> - 실행시간 : 0.01 ~ 0.27ms - dfs+양~루트 노드까지의 늑대 수가 적은 양 노드부터 탐색하여 재귀한다. (TC 1개 실패)

<성환> - 

<우빈> - 실행시간: 0.01 ~ 2.39ms, dfs+현재 탐색한 노드들을 저장하고 인접한 노드들을 골라내어 하나씩 탐색한다.

<다은> - 

<현주> - 실행시간: 0.01 ~ 0.97ms, dfs+현재 탐색한 노드들을 기반으로 다음 탐색 후보 노드들을 저장하고 재귀로 후보 노드 하나씩 탐색한다.
  
  문제 특징: 노드의 개수가 적었기 때문에 dfs 완전 탐색이 가능했다. 루트부터 내려오면서 경로를 찾는 구조고 이미 선택한 노드들만 중요하며 경로의 방향은 중요하지 않다.
  dfs+완전 탐색으로 푸는 방법 외에 양을 기준으로 효율적으로 탐색하는 방법도 존재할 수 있지만 예외 케이스가 굉장히 많기 때문에 dfs 완전 탐색이 정석적인 방법으로 보인다.
  
  자료 구조: tree 구조에서 edge가 input으로 주어진다면 각 노드에 인접한 노드를 저장하는 배열의 자료구조를 생성하는 것이 보통 좋다.
  tree에서 dfs를 사용해야 하는 경우 인접한 노드로 한칸씩 이동해야하기 때문에 시간 효율성을 따졌을 때 좋다.
  
  
  
### 22.02.22 - 양궁 대회

| 구분   | 내용                                                     |
| ------ | -------------------------------------------------------- |
| 날짜   | 22.02.22 21:30                                           |
| 참석자 | 진우빈, 이현주, 박주현 이다은, 조란                     |
| 리더   | 박주현                                                 |
| 문제   | https://programmers.co.kr/learn/courses/30/lessons/92342 |
|        | level2/220215_92342                                      |
  
시뮬레이션
- n발의 화살을 0~10 사의 값으로 정하기
- 값은 중복될 수 있고, 순서는 상관 없음 => 중복 조합
- n이 10기때문에, 20 C 10 정도면 풀림 (n이 작기에 가능한 풀이법)
- 백트랙킹, next_permutation(C++), combinations_with_repkacement(python)
- 다은

그리디
- 라이언이 가져갈 과녁 점수를 고정함
- 위에서 이기기로 한 점수에서는 어피치보다 딱 1개 더 맞추기 + 질 땐 0개 맞추기 + 화살이 남았다면 0점에 몰아주기
- 1~10점에 대해 이길지말지를 결정하기 때문에 2^10 
- 현주, 주현, 란, 우빈
- 현주 현재 idx까지의 점수를 계속 전달해줌 / 주현, 함수로 마지막에 구함
  
  

  
  
  
  
### 22.03.22 - 평범한 배낭

| 구분   | 내용                                                     |
| ------ | -------------------------------------------------------- |
| 날짜   | 22.03.22 21:00                                           |
| 참석자 | 진우빈, 이현주, 박주현 이다은, 조란, 변성환                    |
| 리더   | 변성환                                                 |
| 문제   | https://www.acmicpc.net/problem/12865                 |
|        | boj/12865                                          |
  
DP(KnapSack - https://namu.wiki/w/%EB%B0%B0%EB%82%AD%20%EB%AC%B8%EC%A0%9C)

- 완전탐색 + 백트래킹으로 문제를 해결하기에 n = 100이므로 시간초과가 날 수 있다. (최악의 경우에 depth = 100인 bianry search tree의 각 노드를 모두 탐색해야함)
- 그리디 또한 매 순간 최적의 해를 찾을 수 있는 방법이 없기 때문에 실패.
- DP를 이용해야 한다. 하지만 아래와 같이 1차원 DP를 하다보면 이전 단계에서 까지해서 고른 물건들로 x kg으로 만들 수 있는 최대 가치 데이터가 필요할 수 있다. 아래 표에서 보면 무게 3, 가치 6인 물건을 집은 후 최대 가치를 따질 때, 이전 까지의 물건으로 4kg을 만들었을 때의 최대 가치 데이터가 필요함을 알 수 있다.
  ![image](https://user-images.githubusercontent.com/37177508/159924470-810e1f66-45f4-4a25-bd24-23d1d50379a7.png)

- 따라서 위의 예시에서는 아래와 같이 해당 물건까지 골랐을 때 4kg을 조합해서 만들 수 있는 최대 가치를 저장하는 DP 열을 따로 만들어 줘야 한다.
  ![image](https://user-images.githubusercontent.com/37177508/159923023-d99c9b2d-5a95-45e1-a98c-6ffd86676c16.png)

  - 하지만 위의 예시가 아닌 다른 경우에는 다른 무게에 관한 데이터가 필요할 수 있으므로, 아래와 같이 2차원으로 0 kg ~ K kg의 가치를 매 순간 갱신 해 주는 2차원 DP를 해야 한다.(이것이 바로 냅색 알고리즘)
  ![image](https://user-images.githubusercontent.com/37177508/159923228-3d53d243-7751-418e-9722-7d672371a0e3.png)
- 나 빼고 다들 잘 풀었고, 여기에 설명하기엔 매우 복잡하기 때문에 자세한 설명은 생략함..혹시나 이해가 안되면 리더에게 물어보자.

  #### Tips!
- 맨 처음 2차원 배열로 100x100000의 int 타입의 메모리를 선언하게되면 메모리 낭비가 심하므로, vector로 순간순간의 data를 갱신 해 준다.(현주코드 참고)

  ​
  
  
