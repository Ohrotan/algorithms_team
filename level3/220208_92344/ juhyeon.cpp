#include <string>
#include <vector>
#include <iostream>

//0.01~29.61 ~115MB
using namespace std;
int v[1010][1010];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int r= board.size();
    int c = board[0].size();
    int sz = skill.size();
    // vector <vector<int>> v(sz+1,vector <int>(sz+1,0));
    for(int i=0; i<sz; i++){
        if(skill[i][0] ==1){
            v[skill[i][1]][skill[i][2]] -= skill[i][5];
            v[skill[i][3]+1][skill[i][4]+1] -= skill[i][5];
            v[skill[i][3]+1][skill[i][2]] += skill[i][5];
            v[skill[i][1]][skill[i][4]+1] += skill[i][5];
        }
        else{
            v[skill[i][1]][skill[i][2]] += skill[i][5];
            v[skill[i][3]+1][skill[i][4]+1] += skill[i][5];
            v[skill[i][3]+1][skill[i][2]] -= skill[i][5];
            v[skill[i][1]][skill[i][4]+1] -= skill[i][5];
        }
    }
    for(int i=0; i<r; i++){
        for(int j=1; j<c; j++){
            v[i][j] += v[i][j-1];
        }
    }
    for(int j=0; j<c; j++){
        for(int i=1; i<r; i++){
            v[i][j] += v[i-1][j];
        }
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(board[i][j] + v[i][j] >0) answer++;
        }
    }
    return answer;
}