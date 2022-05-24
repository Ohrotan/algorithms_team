#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (int placeNumber = 0; placeNumber < 5; placeNumber++) {     //각 응시자들이 있는 공간 5번 반복
        int result = 1;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {

                if (places[placeNumber][i][j] == 'O' || places[placeNumber][i][j] == 'X') continue;     //비어있거나 칸막이 있는곳은 굳이 검사할 필요ㄴㄴ

                //상하좌우 바로 옆에 사람이 있으면 거리두기 만족X
                if ((i >= 1 && places[placeNumber][i - 1][j] == 'P') ||
                    (i <= 3 && places[placeNumber][i + 1][j] == 'P') ||
                    (j >= 1 && places[placeNumber][i][j - 1] == 'P') ||
                    (j <= 3 && places[placeNumber][i][j + 1] == 'P'))
                {
                    result = 0;
                    break;
                }

                //중간에 칸막이가 아니면서 상상 하하 좌좌 우우에 사람이 있으면 거리두기 만족X
                if ((i >= 2 && places[placeNumber][i - 1][j] != 'X' && places[placeNumber][i - 2][j] == 'P') ||
                    (i <= 2 && places[placeNumber][i + 1][j] != 'X' && places[placeNumber][i + 2][j] == 'P') ||
                    (j >= 2 && places[placeNumber][i][j - 1] != 'X' && places[placeNumber][i][j - 2] == 'P') ||
                    (j <= 2 && places[placeNumber][i][j + 1] != 'X' && places[placeNumber][i][j + 2] == 'P'))
                {
                    result = 0;
                    break;
                }

                //대각선 방향에 사람이 있으면서 그 대각선과 크로스 되는 부분의 두 자리가 둘다 칸막이가 아니면 거리두기 만족X
                if (((i >= 1 && j >= 1 && (places[placeNumber][i - 1][j] != 'X' || places[placeNumber][i][j - 1] != 'X')) && places[placeNumber][i - 1][j - 1] == 'P') ||
                    ((i >= 1 && j <= 3 && (places[placeNumber][i - 1][j] != 'X' || places[placeNumber][i][j + 1] != 'X')) && places[placeNumber][i - 1][j + 1] == 'P') ||
                    ((i <= 3 && j >= 1 && (places[placeNumber][i + 1][j] != 'X' || places[placeNumber][i][j - 1] != 'X')) && places[placeNumber][i + 1][j - 1] == 'P') ||
                    ((i <= 3 && j <= 3 && (places[placeNumber][i + 1][j] != 'X' || places[placeNumber][i][j + 1] != 'X')) && places[placeNumber][i + 1][j + 1] == 'P'))
                {
                    result = 0;
                    break;
                }

            }
            if (result == 0) break; //이미 거리두기 만족 못한 상태면 반복 중단
        }
        answer.push_back(result);
    }


    return answer;
}
