#include <vector>
#include <algorithm>

using namespace std;

struct Sheep{
    int id;
    int wolfCnt;
    bool valid;
};
bool sheepCompare(const Sheep &a, const Sheep &b) { 
    if (a.valid && b.valid) {
        return a.wolfCnt < b.wolfCnt;
    } else if (a.valid) {
        return true;
    } else {
        return false;
    }
}
vector<int> info;
vector<vector<int>> edges;

int res = 0;

// 루트까지 가는데 처리해야하는 늑대수
int countWolf(int id) {
    int wolfCnt = 0;
     while (id != 0) {
        for (auto ed : edges) {
            if (ed[1] == id) {
                if (info[ed[0]] == 1) { wolfCnt++; } 
                id = ed[0];
                break;
            }
        }
    }
    return wolfCnt;
}
// 늑대 처리 info 배열에서 늑대를 0으로 바꿈
void removeWolf(int id) {
    while (id != 0) {
        for (auto ed : edges) {
            if (ed[1] == id) {
                info[ed[0]] = 0;
                id = ed[0];
                break;
            }
        }
    }
}
void func(int sheepCnt, int wolfCnt, vector<Sheep> sheeps) {
    // countWolf
    for (int i = 0; i < sheeps.size(); ++i) {
        if (sheeps[i].valid) {
            sheeps[i].wolfCnt = countWolf(sheeps[i].id);
        }
    }
    // 늑대 적은 순으로 정렬
    sort(sheeps.begin(), sheeps.end(), sheepCompare);
    int last = 0;
    
    for (int i = 0; i < sheeps.size(); ++i) {
        if (!sheeps[i].valid) continue;
        
        if (sheeps[i].wolfCnt == 0) {
            sheepCnt++;
            sheeps[i].valid = false;
        } else if (last == 0 || last == sheeps[i].wolfCnt) {
            last = sheeps[i].wolfCnt;
            if (sheeps[i].wolfCnt + wolfCnt < sheepCnt) {
                // 양처리
                vector<int> tInfo = info; // removeWolf에서 info 배열을 바꾸기 때문에 복구를 위해 저장해둠
                removeWolf(sheeps[i].id);
                wolfCnt += sheeps[i].wolfCnt;
                sheepCnt++;
                sheeps[i].valid = false;
                
                func(sheepCnt, wolfCnt, sheeps);
                
                // 양복구
                info = tInfo;
                wolfCnt -= sheeps[i].wolfCnt;
                sheepCnt--;
                sheeps[i].valid = true;
            } else {
                break; // break하는 이유는 이번 양을 처리하지 못한다면 다음 양(늑대수가 같거나 많음)들도 당연히 안 되기 때문
            }
        } else {
            break; // break하는 이유는 다음 양들에 대한 처리는 위의 func 에서 할 것이기 때문
        }
    }
    if (res < sheepCnt) {
        res = sheepCnt;
    }
}
int solution(vector<int> _info, vector<vector<int>> _edges) {
    info = _info;
    edges = _edges;
    vector<Sheep> sheeps;
    for (int i = 0; i< info.size(); i++) { 
        if (info[i] == 0){
            sheeps.push_back({i,-1,true});
        }
    }
    func(0,0,sheeps);
    
    return res;
}
