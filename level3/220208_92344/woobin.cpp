#include <vector>
#include <cstring>
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int N = static_cast<int>(board.size());
    int M = static_cast<int>(board[0].size());
    int pointMap[N + 1][M + 1];
    memset(pointMap, 0, sizeof(pointMap));
    
    for(auto&& e : skill) {
        int type = e.at(0);
        int r1 = e.at(1);
        int c1 = e.at(2);
        int r2 = e.at(3);
        int c2 = e.at(4);
        int damage = e.at(5);
        damage = (type == 2) ? damage : damage * (-1);
        
        // 누적합 포인트 생성
        pointMap[r1][c1] += damage;
        pointMap[r2 + 1][c2 + 1] += damage;
        pointMap[r1][c2 + 1] -= damage;
        pointMap[r2 + 1][c1] -= damage;
    }

    // 열을 누적합
    for(int i = 0; i < N + 1; i++) {
        for(int j = 1; j < M + 1; j++) {
            pointMap[i][j] += pointMap[i][j - 1];
        }
    }
    
    // 행을 누적합
    for(int j = 0; j < M + 1; j++) {
        for(int i = 1; i < N + 1; i++) {
            pointMap[i][j] += pointMap[i - 1][j];
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            pointMap[i][j] += board.at(i).at(j);
            answer = pointMap[i][j] > 0 ? answer + 1 : answer;
        }
    }
    
    return answer;
}
