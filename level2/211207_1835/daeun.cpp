#include <string>
#include <vector>
#include <map>
// #include <stdio.h>

using namespace std;

int cnt;

void DFS(int n, vector<string> data, int L, int friends_num, char friends[], int friends_idx[], int ch[]){
    
    if (L == friends_num){       
        int flag = 1;
        for (int i = 0; i < n; i++){
            int friend1, friend2;
            for(int j = 0; j < friends_num; j++){
                if (friends[j] == data[i].at(0))
                    friend1 = friends_idx[j];
                if (friends[j] == data[i].at(2))
                    friend2 = friends_idx[j];
            }
            int gap = (data[i].at(4) - '0') + 1;
            char operation = data[i].at(3);
            // printf("%c ", operation);
            if (operation == '='){
                if ((abs(friend1 - friend2) != gap)){
                    flag = 0;
                    // printf("aaaa");
                    break;
                }
            }
            else if (operation == '<'){
                if ((abs(friend1 - friend2) >= gap)){
                    flag = 0;
                    break;
                }
            }
            else if (operation == '>'){
                if ((abs(friend1 - friend2) <= gap)){
                    flag = 0;
                    break;
                }
            }
        }
        if(flag)
            cnt++;
    }
    else{
        for(int i = 0; i < friends_num; i++){
            if (ch[i] == 0){
                ch[i] = 1;
                friends_idx[L] = i;
                DFS(n, data, L+1, friends_num, friends, friends_idx, ch);
                ch[i] = 0;
            }

        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    cnt = 0;
    const int friends_num = 8;
    char friends[8] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    int friends_idx[8] = {-1, };
    int ch[8] = {0, };
    DFS(n, data, 0, friends_num, friends, friends_idx, ch);

    return cnt;
}
