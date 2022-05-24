#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (int placeNumber = 0; placeNumber < 5; placeNumber++) {
        int result = 1;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {

                if (places[placeNumber][i][j] == 'O' || places[placeNumber][i][j] == 'X') continue;

                if ((i >= 1 && places[placeNumber][i - 1][j] == 'P') ||
                    (i <= 3 && places[placeNumber][i + 1][j] == 'P') ||
                    (j >= 1 && places[placeNumber][i][j - 1] == 'P') ||
                    (j <= 3 && places[placeNumber][i][j + 1] == 'P'))
                {
                    result = 0;
                    break;
                }

                if ((i >= 2 && places[placeNumber][i - 1][j] != 'X' && places[placeNumber][i - 2][j] == 'P') ||
                    (i <= 2 && places[placeNumber][i + 1][j] != 'X' && places[placeNumber][i + 2][j] == 'P') ||
                    (j >= 2 && places[placeNumber][i][j - 1] != 'X' && places[placeNumber][i][j - 2] == 'P') ||
                    (j <= 2 && places[placeNumber][i][j + 1] != 'X' && places[placeNumber][i][j + 2] == 'P'))
                {
                    result = 0;
                    break;
                }

                if (((i >= 1 && j >= 1 && (places[placeNumber][i - 1][j] != 'X' || places[placeNumber][i][j - 1] != 'X')) && places[placeNumber][i - 1][j - 1] == 'P') ||
                    ((i >= 1 && j <= 3 && (places[placeNumber][i - 1][j] != 'X' || places[placeNumber][i][j + 1] != 'X')) && places[placeNumber][i - 1][j + 1] == 'P') ||
                    ((i <= 3 && j >= 1 && (places[placeNumber][i + 1][j] != 'X' || places[placeNumber][i][j - 1] != 'X')) && places[placeNumber][i + 1][j - 1] == 'P') ||
                    ((i <= 3 && j <= 3 && (places[placeNumber][i + 1][j] != 'X' || places[placeNumber][i][j + 1] != 'X')) && places[placeNumber][i + 1][j + 1] == 'P'))
                {
                    result = 0;
                    break;
                }

            }
            if (result == 0) break;
        }
        answer.push_back(result);
    }


    return answer;
}