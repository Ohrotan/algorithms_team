#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
0.04~24ms , 3.8~40mb
*/
long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    //역순 실행
    int x1 =x, y1 =y;
    int x2 =x, y2 =y;
    for(int i=queries.size()-1; i >=0; i--){
        int command = queries[i][0];
        int cnt = queries[i][1];
        switch (command)
        {
        //Left
        case 0:
        if(y1!= 0) y1 += cnt;
        y2 = y2+ cnt < m-1 ? y2+ cnt : m-1;
            break;

        //Right
        case 1:
        if(y2 !=m-1) y2 -= cnt;
        y1 = 0 < y1-cnt ? y1-cnt : 0;
            break;
            
        
        //Up
        case 2:
        if(x1!= 0) x1 += cnt;
        x2 = x2+ cnt < n-1 ? x2+ cnt : n-1;
            break;
        
        //Down
        case 3:
        if(x2 !=n-1) x2 -= cnt;
        x1 = 0 < x1-cnt ? x1-cnt : 0;
            break;
        
        default:
            break;
        }
        if(x1>=n || x2 <0 ||y1>=m || y2 <0) return 0;
    }
    long long X =x2-x1+1;
    long long Y =y2-y1+1;

    return X*Y;
}