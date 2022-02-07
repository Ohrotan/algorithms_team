#include <vector>

using namespace std;
vector<vector<int>> startSkill;
vector<vector<int>> endSkill;
vector<vector<int>> skills;
int R, C;

void init() {
    for (int i = 0; i < R; ++i) {
        vector<int> tmp;
        tmp.assign(C, 0);
        startSkill.push_back(tmp);
        endSkill.push_back(tmp);
    }
    
    for (auto skill : skills) {
        int startR = skill[1];
        int startC = skill[2];
        int endR = skill[3];
        int endC = skill[4];
        int degree = (skill[0] == 1? -1 : 1)*skill[5];
        
        for (int r = startR; r <= endR; ++r) {
            startSkill[r][startC] += degree;
            endSkill[r][endC] += degree;
        }
    }
}

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    skills = skill;
    R = board.size();
    C = board[0].size();
    int res = 0;
    
    init();
    
    for (int r = 0; r < R; ++r) {
        int skillSum = 0;
        for (int c = 0; c < C; ++c) {
            skillSum += startSkill[r][c];
            board[r][c] += skillSum;
            skillSum -= endSkill[r][c];
            if (board[r][c] > 0) {
                res++;
            }
        }
    }
    
    return res;
}
