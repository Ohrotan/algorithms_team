// 최대 시간 복잡도 & 메모리 32~36ms, 39.6 MB

// 양쪽 끝만 관리를 해주면 된다.
// 20만*4정도의 시간 복잡도 가능!

#include <string>
#include <vector>
#include <iostream>

using namespace std;
int mm = 0;
int nn = 0;

void updateEdge(vector<int>& edgeIdx, vector<int>& edgeCnt, int dir, int dx);  // 끝 edge의 위치, 끝 edge에 쌓인 count를 매번 업데이트
int getCountOfEdge (vector<int>& edgeIdx, vector<int>& edgeCnt, int type, int xy);  // x, y의 축 쌓인 count 반환
long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    long long answer = -1;
    
    mm = m;
    nn = n;
    vector<int> edgeIdx = {0, m-1, 0, n-1};  // 사각형의 edge의 각 index (좌, 우, 상, 하)
    vector<int> edgeCnt = {1, 1, 1, 1};  // 사각형의 edge에 겹친 개수 (좌, 우, 상, 하)
    
    for (vector<int> query : queries) {
        updateEdge(edgeIdx, edgeCnt, query[0], query[1]);     
    }
    int a = getCountOfEdge(edgeIdx, edgeCnt, 0, y);
    int b = getCountOfEdge(edgeIdx, edgeCnt, 1, x);
    answer = (long long) a * b;
    
    return answer;
}

void updateEdge(vector<int>& edgeIdx, vector<int>& edgeCnt, int dir, int dx) {
    int t1;  // 벽에 가까운 쪽의 edge
    int t2;  // 벽에서 먼 쪽의 edge
    int pm;  // 플러스 or 마이너스 방향
    int wall;  // 현재 부딫힐 벽의 index
    int maxWall;  // 행 or 열의 가능한 최대 index
    switch (dir) {
        case 0:
            t1 = 0; t2 = 1; pm = -1; wall = 0; maxWall = mm-1;
            break;
        case 1:
            t1 = 1; t2 = 0; pm = 1; wall = mm-1; maxWall = mm-1;
            break;
        case 2:
            t1 = 2; t2 = 3; pm = -1; wall = 0; maxWall = nn-1;
            break;
        case 3:
            t1 = 3; t2 = 2; pm = 1; wall = nn-1; maxWall = nn-1;
            break;
    }
    int pmdx = pm*dx;  // 방향+dx
    int n1 = edgeIdx[t1] + pmdx;  // 벽에 가까운 쪽의 edge의 다음 위치 (벽 무시)
    int n2 = edgeIdx[t2] + pmdx;  // 벽에 먼 쪽의 edge의 다음 위치 (벽 무시)
    int n1Cnt = edgeCnt[t1];  // 벽에 가까운 쪽의 edge의 카운트
    int n2Cnt = edgeCnt[t2];  // 벽에 먼 쪽의 edge의 카운트
    
    if (n2 <= 0 || n2 >= maxWall) {
        // 하나로 합쳐진 경우 (둘 다 한쪽 벽에 부딫힌 경우)
        n1Cnt = maxWall+1;  // 최대 개수인 해당 행or열의 개수
        n1 = wall;
        n2Cnt = maxWall+1;
        n2 = wall;
    } else if (n1 < 0 || n1 > maxWall) {
        // 가까운 쪽만 벽에 부딫힌 경우
        n1Cnt += (n1 - wall) > 0 ? (n1 - wall) : -(n1 - wall);
        n1 = wall;
    }
    // 아무것도 부딫히지 않은 경우 다음위치를 이미 갱신했으므로 아무것도 수행 안함
    edgeIdx[t1] = n1;
    edgeIdx[t2] = n2;
    edgeCnt[t1] = n1Cnt;
    edgeCnt[t2] = n2Cnt;
}

int getCountOfEdge (vector<int>& edgeIdx, vector<int>& edgeCnt, int type, int xy) {
    int i1; int i2;
    if (type == 0) {
        // 좌~우
        i1 = 0; i2 = 1;
    } else {
        // 상~하
        i1 = 2; i2 = 3;
    }
    if (xy == edgeIdx[i1]) {
        return edgeCnt[i1];
    } else if (edgeIdx[i1] < xy && xy < edgeIdx[i2]) {
        return 1;
    } else if (xy == edgeIdx[i2]) {
        return edgeCnt[i2];
    } else {
        return 0;
    }
}
