/*
처음에 set으로 풀었다가 시간초과 나서
결국은 연결리스트 구현...
python은 heapq로 해도 시간초과 안났음..

*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;

};

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    stack<Node*> history;
    vector<Node*> table(n);
    vector<bool> remain(n, true);
    
    Node* now;
    //table세팅
    for(int i=0; i<n; i++){
        table[i] = new Node();
        table[i]->data = i;
    }
    //prev, next 설정
    for(int i=0; i<n; i++){
        if(i != 0){ // prev 존재
            table[i]->prev = table[i-1];
        }
        if(i < n-1){ // next 존재
            table[i]->next = table[i+1];
        } 
    }
    now = table[k];
    for(int i =0; i<cmd.size(); i++){
        if(cmd[i][0] == 'D'){
            int cnt = stoi(cmd[i].substr(2));
            while(cnt--) now= now->next;
        }
        else if(cmd[i][0] == 'U'){
            int cnt = stoi(cmd[i].substr(2));
            while(cnt--) now= now->prev;
        }
        else if(cmd[i][0] == 'C'){
            history.push(now);
            remain[now->data] = false;
            if(now->prev){
                now->prev->next = now->next;
            }
            if(now->next){
                now->next->prev = now->prev;
            }
            //현재위치 업데이트
            if(now->next){
                now = now->next;
            }else{
                now = now->prev;
            }    
        }
        else{
            Node* recovery = history.top();
            history.pop();
            remain[recovery->data] = true;
            
            if(table[recovery->data]->prev){
                table[recovery->data]->prev->next = recovery;
            }
            if(table[recovery->data]->next){
                table[recovery->data]->next->prev = recovery;
            }
            
        }
    }
    for(int i = 0; i < remain.size(); i++){
        if(remain[i]){
            answer += 'O';
        }else{
            answer += 'X';
        }
    }
    return answer;

}

/*
set으로 풀이한 방법
#include <string>
#include <vector>
#include <set>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    set<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(i);
    }

    vector<int> memento;
    for (auto& it : cmd) {
        char command = it.substr(0, 1)[0];
        if (command == 'D') {
            int capacity = atoi(it.substr(2, it.length() - 2).c_str());
            auto sit = s.find(k);
            for (int i = 0; i < capacity; i++) {
                ++sit;
            }
            k = *sit;
        }
        else if (command == 'U') {
            int capacity = atoi(it.substr(2, it.length() - 2).c_str());
            auto sit = s.find(k);
            for (int i = 0; i < capacity; i++) {
                --sit;
            }
            k = *sit;
        }
        else if (command == 'C') {
            memento.push_back(k);
            int er = k;
            auto sit = s.find(k);
            ++sit;
            if (sit != s.end()) {
                k = *sit;
            }
            else {
                --sit;  --sit;
                k = *sit;
            }

            s.erase(er);
        }
        else {
            s.insert(memento.back());
            memento.pop_back();
        }
    }

    string answer(n, 'X');
    for (auto& it : s) {
        answer[it] = 'O';
    }
    return answer;
}
*/