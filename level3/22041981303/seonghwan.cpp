/*
    answer += 'O'를 answer = answer + 'O'라고 해서 시간초과 났었음...약 2시간 잡아먹음....다른 하이레벨 언어 쓰는 사람들은 조심해야할듯
    answer += 'O'을 썼을 땐 되고 answer = answer + 'O'을 썼을 땐 안되는 이유에 대해 인터넷도 찾아보고 직접 생각해봤는데 100%확실한 답은
    못 찾았고, 아래 가능성이 있다고 봄
        1. answer + 'O' 연산 결과를 answer에 덮어 쓸 때,answer크기보다 더 큰 저장공간이 필요하기 때문에 realloc가 일어나서 다시 할당 되어야
           하기 때문에 매번 크기 재할당을 하기엔 이에대한 오버헤드가 큼(+=나 append 사용시, 기존 크기보다 넘어서게 되면 기존 크기의 2배의
           크기로 넉넉하게 할당해서 재할당 횟수 = log(n)으로 줄어듦. answer = answer + 'O'는 재할당 횟수 = n인듯)
        2. string은 결국 char배열들의 물리적인 공간의 연속의 집합이므로 string 복사가 일어날 때 첫 번째 문자부터 차례대로 복사가 일어남. 즉,
           answer = answer + 'O'는 맨 첫 문자부터 반복적으로 복사가 일어나서 이에 대한 반복연산 수행으로 시간복잡도 n^2로 늘어남.
    위 두 가지 경우가 그나마 가장 유력하다고보는데 혹시라도 제대로 된 지식 가지고 있으면 꼭 좀 알려주길 부탁드림..
*/

/*
    upperIndex - i번째 행이랑 위로 연결된 행의 번호를 저장
    underIndex - i번째 행이랑 아래로 연결된 행의 번호를 저장
    위 두 배열로 인해 i번째 행의 위아래 주소번지를 알 수 있다.
*/
#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<int> removedIndexStack;
int isDeleted[1000001];
int upperIndex[1000001] = {0, };
int underIndex[1000001] = {0, };
int nowIndex;
int n;

void Down(int count){
    while(count >= 1){
        nowIndex = underIndex[nowIndex];    //count 수 만큼 아래 행으로 계속 이동
        count--;
    }
}

void Up(int count){
    while(count >= 1){
        nowIndex = upperIndex[nowIndex];    //count 수 만큼 위 행으로 계속 이동
        count--;
    }
}

void Remove(){
    removedIndexStack.push(nowIndex);   //쓰레기통에 집어넣기
    isDeleted[nowIndex] = true;         //얜 버린 녀석
    
    if(underIndex[nowIndex] == n){              //자신보다 맨 아래가 없는 경우
        underIndex[upperIndex[nowIndex]] = n;   //자신의 아래 애가 마지막 인덱스보다 더 아래(가상의 인덱스)인 n을 가리킴
        nowIndex = upperIndex[nowIndex];        //자신이랑 연결된 위 인덱스가 현재 인덱스가 됨
    }else if(underIndex[nowIndex] == -1)        //자신보다 맨 위가 없는 경우
    {
        upperIndex[underIndex[nowIndex]] = -1;
        nowIndex = underIndex[nowIndex];
    }else{                                                          //중간에 있는 경우
        upperIndex[underIndex[nowIndex]] = upperIndex[nowIndex];    //양 옆을 서로 연결해준다.
        underIndex[upperIndex[nowIndex]] = underIndex[nowIndex];
        nowIndex = underIndex[nowIndex];
    }
}

void Restore(){
    if(removedIndexStack.size() >= 1){
        int revivedIndex = removedIndexStack.top();     //복구
        removedIndexStack.pop();
        
        isDeleted[revivedIndex] = false;
        upperIndex[underIndex[revivedIndex]] = revivedIndex;    //복구된 녀석의 위아래에 어떤 행이 있는지 입력
        underIndex[upperIndex[revivedIndex]] = revivedIndex;
    }
}

string solution(int nTemp, int k, vector<string> cmd) {
    string answer = 
    
    n = nTemp;
    nowIndex = k;
    
    
    for(int i = 0 ; i < n ; i++){
        upperIndex[i] = i - 1;
        underIndex[i] = i + 1;
    }
    
    int countInt;
    for(int i = 0 ; i < cmd.size() ; i++){
        if(cmd[i][0] == 'D'){
            countInt = stoi(cmd[i].substr(2));
            Down(countInt);
        }else if(cmd[i][0] == 'U'){
            countInt = stoi(cmd[i].substr(2));
            Up(countInt);
        }
        else if(cmd[i][0] == 'C')
            Remove();
        else if(cmd[i][0] == 'Z')
            Restore();

    }
    
    for(int i = 0 ; i < n ; i++){
        if(isDeleted[i] == true){
            answer[i] = 'X';
        }else{
            answer[i] = 'O';
        }
    }
    return answer;
}
