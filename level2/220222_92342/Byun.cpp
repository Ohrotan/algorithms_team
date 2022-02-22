#include <string>
#include <vector>

using namespace std;

void DFS(int scorePoint, int cnt);
void CheckRyanWin();
void CheckLargestScore(int nowScore);
void FindRightAnswer();


int ryanDart[11] = {0, };
int apeachDart[11] = {0, };
int n;
int largestScore;

int count;

vector<vector<int>> answerTemp;
vector<int> answer;

vector<int> solution(int nTemp, vector<int> apeachDartTemp) {
    n = nTemp;
    count = 0;
    largestScore = 0;
    for(int i = 0 ; i < apeachDartTemp.size() ; i++)
        apeachDart[i] = apeachDartTemp[i];
    
    DFS(0,0);
    
    if(answerTemp.size() == 0){
        answer.clear();
        answer.push_back(-1);
        return answer;
    }else{
        FindRightAnswer();
    }
    return answerTemp[0];
}

void DFS(int scorePoint, int cnt){
    if(cnt >= n){
        CheckRyanWin();
        return;
    }
    
    for(int i = 0 ; i < 11 ; i++){
        if(i < scorePoint) continue;
        ryanDart[i]++;
        DFS(i, cnt + 1);
        ryanDart[i]--;
    }
}

void CheckRyanWin(){
    bool isRyanWin = true;
    int ryanScore = 0;
    int apeachScore = 0;
    count++;
    if(count >= 99999999){
        for(int i = 0 ; i < 11 ; i++){
            printf("%d ", ryanDart[i]);
        }
        printf("\n");
    }
    
    for(int i = 0 ; i < 11 ; i++){
        if(ryanDart[i] == 0 && apeachDart[i] == 0) continue;
        
        if(ryanDart[i] > apeachDart[i]){
            ryanScore = ryanScore + 10 - i;
        }else{
            apeachScore = apeachScore + 10 - i;
        }
    }
    
    if(ryanScore > apeachScore) CheckLargestScore(ryanScore);
    
}

void CheckLargestScore(int nowScore){

    if(nowScore >= largestScore){
        largestScore = nowScore;
        vector<int> vectorTemp;
        for(int i = 0 ; i < 11 ; i++){
            vectorTemp.push_back(ryanDart[i]);
        }
        answerTemp.push_back(vectorTemp);
    }
}

void FindRightAnswer(){
    int idx = 10;
    while(answerTemp.size() > 1){
        int largestNumber = 0;
        for(int i = 0 ; i < answerTemp.size() ; i++){
            if(answerTemp[i][idx] > largestNumber) largestNumber = answerTemp[i][idx];
        }
        for(int i = 0 ; i < answerTemp.size() ; i++){
            if(answerTemp[i][idx] != largestNumber){
                answerTemp.erase(answerTemp.begin() + i);
                i--;
            }
        }
        idx--;
    }
}
