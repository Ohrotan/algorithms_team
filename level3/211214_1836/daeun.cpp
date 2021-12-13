#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <deque>

using namespace std;

struct FRIEND{
    char component;
    int y, x;
    int dir_cnt;
    int dir;
};
vector<FRIEND> friends;
char map[100][100];
int ch[10000];
string res;
string answer;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int g_m, g_n;

bool compare(FRIEND a, FRIEND b){
    return a.component < b.component;
}

bool is_remove(FRIEND start_friend){
    deque<FRIEND> dq;
    int cnt[100][100] = {0, };
    cnt[start_friend.y][start_friend.x] = 0;
    dq.push_back(start_friend);

    while(!dq.empty()){
        FRIEND cur_friend;
        cur_friend = dq.front();
        dq.pop_front();
        int y, x, dir_cnt, d;
        y = cur_friend.y;
        x = cur_friend.x;
        dir_cnt = cnt[y][x];
        d = cur_friend.dir;

        //본인이 아닌 같은 문자 찾으면 '.'으로 변경
        if(map[y][x] == start_friend.component && (start_friend.y != y || start_friend.x != x)){
            map[start_friend.y][start_friend.x] = '.';
            map[y][x] = '.';
            return true;
        }

        int ny, nx, nd;
        for(int i = 0; i < 4; i++){
            ny = y + dy[i];
            nx = x + dx[i];
            nd = i;
            if(ny >= 0 && ny < g_m && nx >= 0 && nx < g_n && cnt[ny][nx] < 2 && (map[ny][nx] == '.' || map[ny][nx] == start_friend.component)){
                if(d != nd && d != -1){
                    if(dir_cnt+1 > 1)
                        continue;
                    dq.push_back({map[ny][nx], ny, nx, dir_cnt+1, nd});
                    cnt[ny][nx] = dir_cnt + 1;

                }
                else{
                    dq.push_back({map[ny][nx], ny, nx, dir_cnt, nd});
                    cnt[ny][nx] = dir_cnt;
                }
            }
        }
    }
    return false;
}

void DFS(int L){
    if(L == friends.size()){
        for(int i = 0; i < friends.size(); i++){
            answer = res;
        }
    }
    for(int i = 0; i < friends.size(); i++){
        if(answer.compare("") != 0)
            break;
        if(ch[i] == 0){
            bool success;
            success = is_remove(friends[i]);
            if(!success)
                continue;
            ch[i] = 1;
            res += friends[i].component;
            DFS(L+1);
            ch[i] = 0;
            res.substr(0, res.size()-1);
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int m, int n, vector<string> board) {
    //DFS 순열
    //짝 찾는 경로는 BFS
    res = "";
    answer = "";
    g_m = m;
    g_n = n;
    friends.clear();

    for(int y = 0; y < m; y++){
        for(int x = 0; x < n; x++){
            char temp = board[y][x];
            map[y][x] = temp;
            if('A' > temp || temp > 'Z')
                continue;
            
            int is_exist = 0;
            for(int i = 0; i < friends.size(); i++){
                if(friends[i].component == temp)
                    is_exist = 1;
            }
            if(is_exist == 0){
                friends.push_back({temp, y, x, 0, -1});
            }
        }
    }
    for(int i = 0; i < friends.size(); i++){
        ch[i] = 0;
    }
    //순열 오름차순으로 진행하도록 전처리
    sort(friends.begin(), friends.end(), compare);

    DFS(0);

    if(answer.compare("") == 0)
        return "IMPOSSIBLE";
    return answer;
}
