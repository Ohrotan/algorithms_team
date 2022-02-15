
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> checkConnectionMap(20);
int visited[20] = { 0, };
vector<int> infoTemp;
int wolfCount;
int sheepCount;
int edgeSize;

queue<int> wolfQueue;

void FindSheeps(int rootNode);
void FightWithAllWolves();

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    sheepCount = 0;
    wolfCount = 0;
    infoTemp = info;
    edgeSize = edges.size();

    for (int i = 0; i < edgeSize; i++) {
        checkConnectionMap[edges[i][0]].push_back(edges[i][1]);//노드 연결
        checkConnectionMap[edges[i][1]].push_back(edges[i][0]);//노드 연결
    }


    if (infoTemp[0] != 0) {
        return 0;
    }
    else {
        sheepCount++;
        FindSheeps(0);
    }
    FightWithAllWolves();


    return answer = sheepCount;
}

void FindSheeps(int rootNode) {

    queue<int> sheepQueue;

    sheepQueue.push(rootNode);

    while (sheepQueue.size() > 0) {
        int thisNode = sheepQueue.front();
        sheepQueue.pop();
        visited[thisNode] = 1;

        for (int i = 0; i < checkConnectionMap[thisNode].size(); i++) {
            int nextNode = checkConnectionMap[thisNode][i];
            if (visited[nextNode] == 1) continue;

            if (infoTemp[nextNode] == 1) {//늑대
                if (sheepCount - wolfCount >= 2) {
                    wolfCount++;
                    sheepQueue.push(nextNode);
                }
                else {
                    wolfQueue.push(nextNode);
                }

            }
            else {
                sheepCount++;
                sheepQueue.push(nextNode);
            }
        }
    }
}

void FightWithAllWolves() {

    for (int i = 0; i < wolfQueue.size(); i++) {
        int wolfNode = wolfQueue.front();
        wolfQueue.pop();
        if (sheepCount - wolfCount >= 2) {
            wolfCount++;
            FindSheeps(wolfNode);
            FightWithAllWolves();
        }
        else {
            wolfQueue.push(wolfNode);
        }
    }
}
