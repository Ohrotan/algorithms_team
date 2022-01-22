/*
    실행시간 : 0.01ms~0.48ms, 메모리 : 3.67MB~4.35MB
    1. bfs로 풀었음.
    2. 도로를 건설한다기 보다, 차를 이동하며 통행료를 낸다고 생각하는게 마음편함(직선 : 100원, 코너 : 500원의 통행료 지불)
    2. 방향까지 따져주는 bfs를 생각해야하며, 특정 좌표까지 가는데에 드는 cost가 현재 검사중인 값보다
       작다고 하더라도 방향 조건이 있기 때문에 방향까지 함께 해서 기록 해 줘야 한다.
    3. 따라서 y, x, 방향까지 더해주는 3차원 배열을 활용함.(25x25x4 = 2500이라 별로 크지 않기때문)
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

void ResetTotalCostBoard();

enum {
    up,
    down,
    left,
    right,
    none = -1
};

typedef struct {         //자동차의 구조를 정의
    int y;              //현재 y좌표
    int x;              //현재 x좌표
    int direction;      //현재 차가 달리고 있는 방향()
    int totalCost;      //이 위치에 올 때 까지 드는 비용(도로 건설비용)
} Car;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };//상하좌우
int totalCostBoard[25][25][4];//특정 좌표의 특정 방향에서 차가 왔을 때, 그 차가 낸 통행료의 총합 중 최솟값을 저장하는 배열
                              //y, x, 해당 좌표에 들어왔을 때의 자동차 방향(enum이랑 동일)


int solution(vector<vector<int>> board) {
    int answer = 10000000; int boardSize = board.size();
    queue<Car> q;
    Car carTemp = { 0, 0, none, 0 };                //맨 처음 차의 출발 위치
    q.push(carTemp);

    ResetTotalCostBoard();                          

    while (q.empty() != true) {
        carTemp = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {               //상하좌우
            Car car;                                //이 차는 새 좌표에 갔을 때의 차(carTemp는 기존 좌표에 있는 차)
            car.y = carTemp.y + dy[i];              //차가 새로 갈 좌표를 대입(아직 갈 수 있을진 모름)
            car.x = carTemp.x + dx[i];
            car.direction = i;                      //차가 기존 좌표에서 새로 갈 좌표에 가기위한 방향

            if (car.y < 0 || car.x < 0 || car.y >= boardSize || car.x >= boardSize) continue;//범위 밖이니 패쓰
            if (board[car.y][car.x] == 1) continue;                                          //벽이 있으니 패쓰

            if (carTemp.direction == none || carTemp.direction == car.direction) //처음 출발(none)의 경우, 직선의 경우
                car.totalCost = carTemp.totalCost + 100;                         //직선 건설비용을 더해준다.
            else                                                                 //그게 아니라면 코너이기 때문에
                car.totalCost = carTemp.totalCost + 100 + 500;                   //코너 건설비용 + 직선 건설비용을 더해준다.

            if (totalCostBoard[car.y][car.x][car.direction] > car.totalCost) {   //새로 간 좌표에 같은 방향으로 왔던 애가 건설비용이 더 크다면
                totalCostBoard[car.y][car.x][car.direction] = car.totalCost;     //새로 간 좌표에 새 건설비용을 갱신해준다.
                q.push(car);
            }
        }
    }


    for (int i = 0; i < 4; i++) {//도달지점의 좌표에서 상하좌우 방향으로 도달한 네 가지 경우 중 최저 cost를 찾아서 답으로 해야함
        if (totalCostBoard[boardSize - 1][boardSize - 1][i] < answer)
            answer = totalCostBoard[boardSize - 1][boardSize - 1][i];
    }

    return answer;
}

void ResetTotalCostBoard() {
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 25; j++) {
            for (int k = 0; k < 4; k++) {
                totalCostBoard[i][j][k] = 10000000;//i, j는 각각 y, x의 좌표, k는 해당 좌표에 차가 들어왔을 때의 방향(enum참고)
            }
        }
    }
}