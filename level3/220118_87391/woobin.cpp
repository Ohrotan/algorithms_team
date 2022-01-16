#include <vector>
#include <algorithm>

using namespace std;

// 0번 째 index = 가능한 시작 좌표, 1번 째 index = 가능한 끝 좌표
int pointY[2];
int pointX[2];

// 방향 역으로 계산할 것이기 때문에 문제에서 주어진 것과 반대로
enum Direction {
    RIGHT,
    LEFT,
    DOWN,
    UP
};

long long solution(int N, int M, int y, int x, vector<vector<int>> queries) {
    long long answer = -1;
    
    // 면적 계산할 y,x 좌표 쵸기화
    pointY[0] = y; pointY[1] = y;
    pointX[0] = x; pointX[1] = x;
    
    // 역순으로 탐색하기 위해서 벡터 뒤집음
    std::reverse(queries.begin(), queries.end());
    for(auto e : queries) {
        int command = e.at(0);
        int dx = e.at(1);
        
        // 가독성 좋게 Enum으로 바꿈
        Direction dir = static_cast<Direction>(command);
        
        switch(dir) {
            // 경계 처리를 하면서 면적 계산 가능 위치를 계산해준다
            case Direction::RIGHT : {
                if(pointX[0] != 0) {
                    pointX[0] += dx;
                }
                pointX[1] += dx;
                pointX[1] = pointX[1] > M - 1 ? M - 1 : pointX[1];
                break;
            }
            case Direction::LEFT: {
                if(pointX[1] != M - 1) {
                    pointX[1] -= dx;
                }
                pointX[0] -= dx;
                pointX[0] = pointX[0] < 0 ? 0 : pointX[0];
                break;
            }
            case Direction::DOWN : {
                if(pointY[0] != 0) {
                    pointY[0] += dx;
                }
                pointY[1] += dx;
                pointY[1] = pointY[1] > N - 1 ? N - 1 : pointY[1];
                break;
            }
            case Direction::UP: {
                if(pointY[1] != N - 1) {
                    pointY[1] -= dx;
                }
                pointY[0] -= dx;
                pointY[0] = pointY[0] < 0 ? 0 : pointY[0];
                break;
            }
            default: {
                break;
            }
                
        }
        
        // 이미 이전위치로 갈수 없는 상황
        if(pointY[1] < 0 || pointY[0] > N - 1 || pointX[1] < 0 || pointX[0] > M - 1) {
            answer = 0;
        }
    }
    
    return answer == 0 ? 0 : static_cast<long long>(pointY[1] - pointY[0] + 1)*(pointX[1] - pointX[0] + 1);
    // return answer == 0 ? 0 : static_cast<long long>((pointY[1] - pointY[0] + 1)*(pointX[1] - pointX[0] + 1)); 이건 통과안됨;
    
}
