/*
    1. 이 문제는 시간복잡도를 생각 해 주지 않으면 n^2의 시간복잡도를 가지는 이중for문을 통해서 문제에서 요구하는 가장 짧은 구역을 찾을 수 있는 문제임.
    2. 그러나 10,000x10,000은 안됨.따라서 nlogn 혹은 n의 시간복잡도를 가지는 방법을 생각 해 봐야 함.
    3. (비록 최소범위가 아닐지라도)맨 처음 모든 보석을 다 포함하는 범위를 만든 후 해당 범위에 알파벳이 몇 개 들어있는지 상수의 시간복잡도로 알 수 있다면, n의 시간복잡도가 나오게 된다.
    4. set을 이용하여 보석 종류의 갯수를 구하고, 구간안에 해당 보석이 몇 개 있는지 unordered_map을 이용하여 기록한 후 차츰차츰 범위를
       왼쪽으로 이동 해 나감과 동시에 좁혀가면서(지렁이마냥) 범위내에 보석이 몇 개 들어있는지를 확인하는 방식으로 문제를 풀었다.
*/

#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

set<string> gemSet;                 // 보석의 종류를 겹치지 않게 넣어, 보석의 종류를 세는 용도
unordered_map<string, int> gemMap;  // 조사하고있는 범위 내에 key값의 보석이 얼마나 있는지 value로 나타내주는 용도
vector<int> answer;
int gemQuantity = 0;   
int iter_first = 0;     //범위의 첫번째 지점
int iter_rear = 0;      //범위의 마지막 지점
int interval;

int answerFirst;        //정답이 되는 진열대 맨 앞 넘버
int answerRear;         //정답이 되는 진열대 맨 뒤 넘버

vector<int> solution(vector<string> gems) {
    
    for(int i = 0 ; i < gems.size() ; i++){
        gemSet.insert(gems[i]);
        if(gemSet.size() > gemQuantity){
            gemQuantity = gemSet.size();    // 현재까지 검사했을 때 보석의 가지수
            iter_rear = i;                  // 마지막으로 나온 새로운 보석의 지점
        }
    }
    
    interval = iter_rear - iter_first;  // 맨 처음 새 보석이 나온지점과 맨 마지막으로 새로운 보석이 나온 지점, 그리고 그 인터벌
    answerFirst = iter_first + 1;       // 진열대 번호는 1부터 시작한다.
    answerRear = iter_rear + 1;
    
    for(int i = iter_first ; i <= iter_rear; i++){
        gemMap[gems[i]]++;      // 어떤 보석이 몇 개 있는지 나타내는 unordered_map
    }
    
    while(true){
        
        if(gemMap[gems[iter_first]] == 1){          // 범위의 첫 지점에 있는 보석이 인터벌 상에서 1개만 있다면 무조건 포함해야 하기 때문에 뒤로 못 움직인다.
            iter_rear++;                            // 따라서 뒷 지점을 한 칸 뒤로 옮긴 후 생각.
            if(iter_rear == gems.size()) break;     // 범위의 뒷 지점이 끝이면 계산도 끝
                gemMap[gems[iter_rear]]++;
        }else{
            gemMap[gems[iter_first]]--;             // 만약 범위의 첫 지점에 있는 보석이 현재 범위 내에 2개 이상이라면 첫 지점을 다음으로 옮겨줘야 제일 짧은 구간을 찾을 수 있음.
            iter_first++;
        }
        
        if(iter_rear - iter_first < interval){
            interval = iter_rear - iter_first;
            answerFirst = iter_first + 1;
            answerRear = iter_rear + 1;
        }
    }
    
    
    answer.push_back(answerFirst);
    answer.push_back(answerRear);
    
    
    return answer;
}
