#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> ryan(11,0);
vector<int> answer(11,0);

int max_score;
bool lower_shoot(vector<int> ans, vector<int> ryan){
    for(int i=10; i>=0; i--){
        if(ans[i] < ryan[i]) return true;
        if(ans[i] > ryan[i]) return false;
    }
    return true;
}

int cal(vector<int> app, vector<int> ryan){
    int score_app =0;
    int score_ryan =0;
    for(int i=0; i<11; i++){
        if(app[i] ==0 && ryan[i] == 0) continue;
        
        if(app[i] > ryan[i]){
            score_app += 10-i;
        }
        else{
            score_ryan += 10-i;
        }
    }
    if(score_ryan > score_app) return score_ryan - score_app;
    else return -1;
    
}
void solve(int idx, int chance, vector<int> app, vector<int> ryan){
    if(idx == 11 || chance == 0){
        int score = cal(app,ryan);
        if(score !=-1){
            // 라이언이 승리
            if(chance >0) ryan[idx-1] = chance;
            if(score > max_score){
                max_score = score;
                answer = ryan;
            } 
            else if(max_score == score){
                //같은 경우, 비교해봐야함,
                if(lower_shoot(answer,ryan)) answer = ryan;
            }
            ryan[idx-1] = 0;
        
        }
        return;
    }
    //이길래
    if(app[idx] < chance){
        ryan[idx] = app[idx] +1;
        solve(idx+1, chance-ryan[idx],app, ryan);
        ryan[idx] = 0;
    }
    //질래
    solve(idx+1,chance,app, ryan);
    
}

vector<int> solution(int n, vector<int> info) {
    max_score =-1;
    solve(0, n,info, ryan);
    if(max_score == -1) return {-1};
    return answer;
}