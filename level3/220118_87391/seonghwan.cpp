/*   [y,x]로 함             (x축. 왼쪽으로 갈 수록 커짐)
  (y축. 아래로 갈 수록 커짐)  [0,0] [0,1] [0,2] ...
                           [1,0] [1,1] [1,2] ...
                           [2,0] [2,1] [2,2] ...
                            ↑ ↑
                            y,x
    맨 위 y : yUpper
    맨 아래 y : yUnder
    왼쪽 x : xLeft
    왼쪽 y : xRight

    역으로 생각함. 중간에 장애물이 없으니 직사각형 모양을 유지할꺼고, 맨 마지막 쿼리부터 방향을 거꾸로 생각하면(예로들어, 왼쪽으로 움직였으면 역으로 오른쪽으로 움직여 준다.) 공들이 어디서부터 온 건지 추적할 수 있음. 단, 벽에서 반대쪽으로 갈땐 벽과 그 사이에 공으로 채워져야함.(머릿속으로 생각해보면 답나옴)
    그리고 만약 범위를 벗어나는 쿼리가 있다면(예로들어, yUpper가 yUnder보다 더 큰 경우) 해당하는 공이 없는 경우이므로 바로 0를 리턴함.
*/


#include <string>
#include <vector>

using namespace std;

enum
{
    backToRight,
    backToLeft,
    backToDown,
    backToUp
};//마지막 쿼리부터 시작해서 반대로 생각해 준 방향(==문제에 있는 방향을 점대칭으로 뒤집은 방향)

long long solution(int n, int m, int y, int x, vector<vector<int>> queries) {
    long long answer = 0;
    int querySize = queries.size();

    int direction;
    int distance;

    long long yUpper = y; long long yUnder = y;
    long long xLeft = x; long long xRight = x;

    for (int i = querySize - 1; i >= 0; i--) {//마지막 쿼리부터 역으로 생각하자

        direction = queries.at(i).at(0);
        distance = queries.at(i).at(1);

        switch (direction) {
        case backToRight://오른쪽으로 추적해야하면
            if (xRight != m - 1)//만약 벽에서 시작했다고 하면 그 사이를 전부다 공으로 메워줘야 하기 때문에 xRight 바운더리를 그대로 둔다.
                xRight = xRight - distance;

            xLeft = xLeft - distance;
            if (xLeft < 0)//왼쪽 바운더리를 넘어갈 수 없기 때문
                xLeft = 0;

            if (xRight < xLeft) return 0;//왼쪽 바운더리가 오른쪽으로 넘어갔단건 직사각형 면적이 없다는 것 -> 도착할 수 있는 공은 애초에 없었다.

            break;
        case backToLeft:
            if (xLeft != 0)
                xLeft = xLeft + distance;

            xRight = xRight + distance;
            if (xRight > m - 1)
                xRight = m - 1;

            if (xLeft > xRight) return 0;

            break;
        case backToUp:
            if (yUnder != n - 1)
                yUnder = yUnder - distance;

            yUpper = yUpper - distance;
            if (yUpper < 0)
                yUpper = 0;

            if (yUnder < yUpper) return 0;

            break;

        case backToDown:
            if (yUpper != 0)
                yUpper = yUpper + distance;

            yUnder = yUnder + distance;
            if (yUnder > n - 1)
                yUnder = n - 1;

            if (yUpper > yUnder) return 0;

            break;
        default:
            break;
        }
    }

    answer = (yUnder - yUpper + 1) * (xRight - xLeft + 1);
    return answer;
}