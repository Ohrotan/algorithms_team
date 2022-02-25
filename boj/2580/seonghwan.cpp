/*
 *메모리 : 2020KB, 걸린시간 : 204ms
 *DFS씀. 뭐라고 설명을 요약해야할지 모르겠네...
 */

#include <iostream>
#include <vector>

using namespace std;

int map[9][9] = {0, };
vector<pair<int, int>> emptyPoint;

void Input();
void DFS(int depth);
bool CheckIfWritePossible(int y, int x, int number);
int SetSquareStartPoint(int number);
void PrintMap();
bool isFirstPrint = false;

int main()
{

    Input();

    if (emptyPoint.size() == 0) //스도쿠가 모두 채워져 있을 땐 그대로 출력 해 준다
        PrintMap();
    else
        DFS(0);

    return 0;
}

void Input()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 0)
                emptyPoint.push_back({i, j}); //스도쿠 판에 빈 좌표의 y,x값을 저장
        }
    }
}

void DFS(int depth)
{

    //모든 빈 좌표가 다 채워졌을 경우
    if (depth >= emptyPoint.size())
    {
        PrintMap();
        return;
    }

    //숫자 1부터 9까지 현재 검사중인 칸에 넣을 수 있는지 검사 후 넣을 수 있으면 넣고 DFS, 아니면 패스
    for (int i = 1; i <= 9; i++)
    {
        if (CheckIfWritePossible(emptyPoint[depth].first, emptyPoint[depth].second, i) == true)
        {
            map[emptyPoint[depth].first][emptyPoint[depth].second] = i;
            DFS(depth + 1);
            map[emptyPoint[depth].first][emptyPoint[depth].second] = 0;
        }
    }
}

//y,x 자리에 number를 입력해도 스도쿠 규칙에 어긋나지 않는지 확인하는 함수
bool CheckIfWritePossible(int y, int x, int number)
{
    for (int i = 0; i < 9; i++)
    {
        if (map[y][i] == number) return false; //가로 확인
        if (map[i][x] == number) return false; //세로 확인
    }

    //y,x에 해당하는 정사각형의 맨 왼쪽 위 좌표 구하기
    int squareStartY = SetSquareStartPoint(y);
    int squareStartX = SetSquareStartPoint(x);

    //정사각형에 스도쿠 규칙으로 넣을 수 있는지 확인
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (map[squareStartY + i][squareStartX + j] == number) return false;
        }
    }

    return true; //위 과정을 거쳤을 때 모두 통과했다면 y,x에 number 입력 가능
}

int SetSquareStartPoint(int number)
{
    if (0 <= number && number <= 2) return 0;
    if (3 <= number && number <= 5) return 3;
    if (6 <= number && number <= 8) return 6;
}

void PrintMap()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    exit(0); //한 번 완성된 스도쿠 맵을 프린트 했으면 프로그램을 종료할 것
}
