//반타작 시간초과..~  수졍듕..
#include <string>
#include <vector>
#include <deque>
#include <stdio.h>

using namespace std;

int num;
vector<int> tmp(11, 0);
vector<int> res(11, 0);
vector<int> apeach(11, 0);
int max_gap = 0;


void dfs(int L){
    
    if(L == num){
        int ap_total = 0;
        int ry_total = 0;
        for(int i = 0; i < 11; i++){
            if(apeach[i] == 0 && tmp[i] == 0) continue;
            if (apeach[i] >= tmp[i]) ap_total += 10-i;
            else ry_total += 10 - i;
        }
        
        if(max_gap <= ry_total - ap_total) {
            max_gap = ry_total - ap_total;
            for(int i = 0; i < 11; i++){
                res[i] = tmp[i];
                // printf("%d ", tmp[i]);
            }
            // printf("\n");
        }
        return;
    }
    else{
        for(int i = 0; i < 11; i++){
            if(tmp[i] > apeach[i])
                continue;
            if(apeach[i] > num - L)
                continue;
            tmp[i]++;
            dfs(L+1);
            tmp[i]--;
        }
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    num = n;
    for(int i = 0; i < 11; i++){
        apeach[i] = info[i];
    }
    dfs(0);
    
    int flag = 0;
    for(int i = 0; i < 11; i++){
        if(res[i] != 0){
            flag = 1;
        }
    }

    if(flag == 1){
        return res;
    }
    else{
        res.clear();
        res.push_back(-1);
        return res;
    }
}
