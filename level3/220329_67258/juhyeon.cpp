#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int>answer(2);
    answer[0] = 1;
    answer[1] = gems.size();
    int s = 0; 
    int e = 0; 
    int distance = gems.size()-1; 
    // end-start의 값

    set<string> g_set(gems.begin(), gems.end());
    int total = g_set.size();

    map<string, int> m;
    while(true) {
         // 보석 다 구했으면
        if(m.size() == total) {
            //현재 구간이랑 미리 구한 최단 구간 비교
            if(e-s<distance) { 
                distance = e-s;
                answer[0] = s+1;
                answer[1] = e;
            }
            // 보석 개수 1개
            if(m[gems[s]] == 1) {
                m.erase(gems[s]);
                s++; 
            }
            // 보석 개수 여러개
            else {
                m[gems[s]]--;
                s++;
            }
        }
        //끝까지 봄
        else if(e == gems.size())
            break;
        //계속 찾기
        else { 
            m[gems[e]]++;
            e++;
        }
        
    }    
    return answer;
}