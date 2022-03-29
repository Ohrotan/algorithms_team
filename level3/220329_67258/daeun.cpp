#include <string>
#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    // deque 1개(s,e포인트), dict 1개
    
    int s = 0, e = 0;
    int N = gems.size();
    map<string, int> gemDict;
    gemDict[gems[0]] = 1;
    
    for (int i = 1; i < N; i++){
        // while dict에 존재하는 보석이 2보다 작을 때 까지: s++ if i번째 보석이 s번째 보석과 같다면 else continue
        if (gems[s] == gems[i]){
            gemDict[gems[i]] += 1;
            while (s<i){
                if(gemDict.find(gems[s]) != gemDict.end()){
                    cout << gems[s] << " " << gemDict.find(gems[s])->second <<endl;
                    if (gemDict.find(gems[s])->second >= 2){
                        gemDict[gems[s]] -= 1;
                        s++;
                    }
                    else{
                        break;
                    }
                }
            }
            e = i;
        }
        else{
            // e = i if i번째 보석이 dict에 없다면 else continue
            if (gemDict.find(gems[i]) == gemDict.end()){
                e = i;
                gemDict[gems[i]] = 1;
            }
            else {
                gemDict[gems[i]] += 1;
            }
        }  
    }
    
    answer.push_back(s+1);
    answer.push_back(e+1);
    
    return answer;
}
