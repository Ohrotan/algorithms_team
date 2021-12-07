# algorithms_team
[스터디 내용](#study)  
[21.12.07 - 단체사진 찍기 (DFS, Back Tracking, Permutation)](#211207)  
[21.12.14 - 리틀 프렌즈 사천성](#211214)  



## 문제목록

| 번호 | 날짜     | 문제                                                    |
| ---- | -------- | ------------------------------------------------------- |
| 1    | 21.12.07 | https://programmers.co.kr/learn/courses/30/lessons/1835 |
| 2    | 21.12.14 | https://programmers.co.kr/learn/courses/30/lessons/1836 |


## 진행 규칙

- 월요일 밤까지 코드 업로드
- 화요일 21시에 webex 모임
- 업로드 경로 level?/날짜_문제번호/이름.cpp
- git push 는 master로
- 리더 순번: 조란-변성환-이다은-이현주-박주현

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
| 문제   | https://programmers.co.kr/learn/courses/30/lessons/1836 |







