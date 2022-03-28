#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;


vector<int> solution(vector<string> gems) {
    vector<int> answer;
    
    unordered_map<string, int> map;
    int gemUniqueCount = 0;
    int gemCount = 0;
    int shortestS = 0;
    int shortestE = gems.size()-1;
    for (string gem : gems) {
        if (map.count(gem) == 0) {
            map[gem] = 0;
            ++gemUniqueCount;
        }
    }
    
    int start = 0;
    int end = -1;
    int tmpsize = gems.size();
    // cout << end << " " << gems.size() << " " << gemUniqueCount << '\n';

    while (true) {        
        if (gemCount == gemUniqueCount) {  // 모든 보석을 포함할 때
            if (shortestE - shortestS > end - start) {  // 가장 짧은 구간일 때
                shortestE = end;
                shortestS = start;
                if (shortestE == shortestS) break;
            }
            // 구간 왼쪽부분을 감소시킴
            map[gems[start]] -= 1;
            if (map[gems[start]] == 0) {
                --gemCount;
            }
            ++start;
        } else {
            // 구간 오른쪽부분을 증가시킴
            ++end;
            if (end >= gems.size()) break;
            if (map[gems[end]] == 0) {
                ++gemCount;
                map[gems[end]] = 1;
            } else {
                map[gems[end]] += 1;
            }
        }
        // cout << start << " " << end << " " << gemCount << " " << map[gems[end]] << '\n';
    }
    answer.push_back(shortestS+1);
    answer.push_back(shortestE+1);
    
    return answer;
}
