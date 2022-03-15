// 2412kb	16ms

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int n;
vector<int> line;

int main(void){
    scanf("%d", &n);
    int tmp;
    scanf("%d", &tmp);
    line.push_back(tmp);
    for (int i = 0; i < n-1; i++){
        scanf("%d", &tmp);
        
        if(tmp > line[line.size()-1])
            line.push_back(tmp);
        else{
            // 이분탐색
            int l = 0;
            int r = line.size()-1;
            int mid;
            while(l < r){
                mid = (r + l) / 2;
                if (tmp <= line[mid])
                    r = mid;
                else
                    l = mid + 1;
            }
            line[r] = tmp;
        }
    }
    int cnt = n - line.size();
    printf("%d\n", cnt);
    return 0;
}
