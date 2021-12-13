#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void ArrangeDFS(int depth);
void CheckArrangementState();

bool isAlreadySat[8] = { false }; //이미 앉아있는지 확인

char name[8] = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };//사람 이니셜 순서대로 저장
char satName[8];//해당 번호의 자리에 앉은 사람 이니셜 저장


//전역변수로 복사
int nTemp;
int answerTemp;
vector<string> dataTemp;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요. 응 ㅅㅂ
int solution(int n, vector<string> data) {
    //전역변수로 데이터 이동
    answerTemp = 0;
    nTemp = n;
    dataTemp = data;
    int answer;

    //모든 경우의수를 찾는다. Permutation(8!)
    ArrangeDFS(0);

    //정답 옮겨적기
    answer = answerTemp;

    return answer;
}


void ArrangeDFS(int depth) {

    if (depth == 8) {//전부 다 배치한 경우
        CheckArrangementState();//모든 조건을 충족하는 녀석인지 확인
        return;
    }

    for (int i = 0; i < 8; i++) {       //i는 자리번호를 뜻함. 맨 첫번째 자리에서부터 확인
        if (isAlreadySat[i] == false) { //비었으면
            isAlreadySat[i] = true;     //앉히고
            satName[i] = name[depth];   //이름 기록하고
            ArrangeDFS(depth + 1);      //다음 녀석 앉히자!
            isAlreadySat[i] = false;    //되돌아와서 다음 노드로 ㄱㄱ
        }
    }
}

void CheckArrangementState() {
    unordered_map<char, int> location;  //각각의 사람이 몇 번째 의자에 앉았는지 기록하는 해시맵

    for (int i = 0; i < 8; i++) {
        location[satName[i]] = i;       //누가 몇 번째에 앉았는가?
    }

    int loc1, loc2;     //두 녀석의 위치
    int distance;       //두 녀석 사이에 몇 명 있는지

    for (int i = 0; i < nTemp; i++) {
        //위치정보 저장
        loc1 = location[dataTemp[i][0]];
        loc2 = location[dataTemp[i][2]];

        //거리 계산
        if (loc1 >= loc2) {
            distance = loc1 - loc2 - 1;
        }
        else {
            distance = loc2 - loc1 - 1;
        }

        //조건 만족하는지 확인. 하나라도 만족 안하면 바로 함수 종료 후 다음 순서를 나열해 본다.
        switch (dataTemp[i][3]) {
        case '=': if (distance != ((int)dataTemp[i][4] - 48)) return; break;
        case '<': if (distance >= ((int)dataTemp[i][4] - 48)) return; break;
        case '>': if (distance <= ((int)dataTemp[i][4] - 48)) return; break;
        default:                                                      break;
        }
    }
    answerTemp++; //이까지 왔다면 모든 조건을 만족한 것이니 정답++
}