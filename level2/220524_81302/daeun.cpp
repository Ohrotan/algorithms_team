#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int isnextby(vector<string> place) {
    int board[5][5];
    for (int y = 0; y < place.size(); y++) {
        for (int x = 0; x < 5; x++) {
            if (place[y][x] == 'P') board[y][x] = 1;
            if (place[y][x] == 'O') board[y][x] = 0;
            if (place[y][x] == 'X') board[y][x] = -1;
        }
    }
    
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            if (board[y][x] != 1) continue;
            for (int i = 0; i < 8; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
                if (i%2 == 0 && board[ny][nx] == 1) return 0;
                if (i%2 == 1 && board[ny][nx] == 1) {
                    if (board[y][nx] == 0 || board[ny][x] == 0) return 0;
                }
                if (i%2 == 0 && board[ny][nx] == -1) {
                    continue; 
                }
                if (i%2 == 0 && board[ny][nx] == 0) {
                    ny += dy[i];
                    nx += dx[i];
                    if (board[ny][nx] == 1) return 0;
                }
            }
        }
    } 
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    int TC = 0;
    while (TC < 5) {
        int flag = 1;
        cout << "TC: " << TC << endl;
        if (!isnextby(places[TC])) flag = 0;
        
        answer.push_back(flag);
        TC++;
    }
    return answer;
}
