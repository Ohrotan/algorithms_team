/*
    <1> (r1,c1)~(r2, c2)를 공격한다고 가정했을 때, 사실상 공격2번 + 치유2번이 이루어진다고 가정함
        예로들어,
            1. Area1 - (r1,c1)~(N, M)는 공격
            2. Area2 - (r2 + 1, c1) ~ (N, M)은 치유(1번 공격이랑 상쇄시키기 위함. 사실 여긴 공격하면 안되는 곳이잖아?)
            3. Area3 - (r1, c2 + 1) ~ (N, M)은 치유(1번 공격이랑 상쇄시키기 위함. 사실 여긴 공격하면 안되는 곳이잖아?)
            4. Area4 - (r2 + 1, c2 + 1) ~ (N, M)은 공격(여긴 공격1번 당하고 치유 2번 당했으니 다시 공격 1번 해 줘야 아무일도 안 일어난게 됨)
            5. 치유일 때는 반대로!!

    <2> 공격 혹은 치유가 시작되는 좌표에 공격이나 치유의 크기를 담은 배열을 만듬(leftTopAccumulationDegree).
    <3> 공격이나 힐이 들어올 때 leftTopAccumulationDegree 배열에 <1>의 규칙으로 총 4개의 영역의 시작 point에 degree를 축척해줌
    <4> 스킬이 전부 끝나고 난 후 leftTopAccumulationDegree 배열의 왼쪽 위 부터 오른쪽 아래로 점차적으로 degree를 확대시켜 나가야 한다.
            1. 계산중인 좌표의 값에 위에 행의 값을 더해준다.(범위 벗어나면 말고)
            2. 계산중인 좌표의 값에 왼쪽 행의 값을 더해준다.(범위 벗어나면 말고)
            3. 계산중인 좌표의 값에 왼쪽 위의 값을 빼 준다. 이는 1, 2를 진행하면서 중복해서 값이 더해졌기 때문. 다시말해서 [i - 1][j - 1]에 있는
               값은 [i][j]에 1번만 더해져야 한다.
    <5> <4>까지 끝내고 나면 leftTopAccumulationDegree에는 각 좌표에 있는 건물들이 받은 총 데미지가 저장됨. 여기다가 건물의 내구도를 더함
    <6> <5>까지 완료한 최종 건물의 내구도가 1 이상이면 answer++ 하고 0이하면 와르르맨션
*/

#include <string>
#include <vector>

using namespace std;

int leftTopAccumulationDegree[1000][1000] = { 0, };//<2>부분. 해당 배열에 들어있는 값의 의미는 해당 좌표부터 (N, M)까지
                                                  //공격 혹은 힐을 할 크기를 뜻한다. 이는 skill을 받을 때마다 축척된다.

int solution(vector<vector<int>> board, vector<vector<int>> skill) {

    int answer = 0;
    int sizeY = board.size();
    int sizeX = board.at(0).size();

    //<3>부분
    for (int i = 0; i < skill.size(); i++) {
        if (skill[i][0] == 2) skill[i][5] = -skill[i][5];//힐일 경우엔 반대로 뒤집어 줘야 한다.

        leftTopAccumulationDegree[skill[i][1]][skill[i][2]] -= skill[i][5];//Area1

        if (skill[i][3] + 1 < sizeY)//Area2가 없을 경우도 있음
            leftTopAccumulationDegree[skill[i][3] + 1][skill[i][2]] += skill[i][5];//Area2
        if (skill[i][4] + 1 < sizeX)//Area3이 없을 경우도 있음
            leftTopAccumulationDegree[skill[i][1]][skill[i][4] + 1] += skill[i][5];//Area3
        if (skill[i][3] + 1 < sizeY && skill[i][4] + 1 < sizeX)//Area4가 없을 경우도 있음
            leftTopAccumulationDegree[skill[i][3] + 1][skill[i][4] + 1] -= skill[i][5];//Area4
    }

    //<4>부분
    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {
            if (i - 1 >= 0) {
                leftTopAccumulationDegree[i][j] += leftTopAccumulationDegree[i - 1][j];//<4> - 1부분
            }
            if (j - 1 >= 0) {
                leftTopAccumulationDegree[i][j] += leftTopAccumulationDegree[i][j - 1];//<4> - 2부분
            }
            if (i - 1 >= 0 && j - 1 >= 0) {
                leftTopAccumulationDegree[i][j] -= leftTopAccumulationDegree[i - 1][j - 1];//<4> - 3부분
            }
        }
    }

    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {
            if (leftTopAccumulationDegree[i][j] + board[i][j] >= 1) answer++;//<5>부분, <6>부분
        }
    }

    return answer;
}