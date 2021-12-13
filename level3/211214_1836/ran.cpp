// vector<CardInfo> -> 통과 (1.42ms, 4.32MB)
// map<CardInfo> -> 통과 (2.31ms, 4.25MB)

#include <string>
#include <vector>

using namespace std;

struct Point {
    int r = -1; // row
    int c = -1; // column
};

struct CardInfo {
    Point one; // 첫번째 카드
    Point two;
    bool direct = false; // 두 카드가 직선인 경우
    Point mid1; // 두 카드간 경로의 꺾이는 점
    Point mid2; 
    
    void findMidPoints() {
        if (one.r == two.r || one.c == two.c) {
            direct = true;
        } else {
            mid1.r = one.r;
            mid1.c = two.c;
            mid2.r = two.r;
            mid2.c = one.c;
        }
    }
};

vector<CardInfo> cards;
vector<string> board;
string answer;
int m, n, cardCnt = 0;

void init() {
    cardCnt = 0; // 카드 종류 개수
    cards.clear();
    answer = "";
    for (int i = 0; i < 27; ++i) { // A~Z
        cards.emplace_back(CardInfo());
    }
    
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            int num = board[r][c];
            if (num > 'Z' || num < 'A') continue;
            num -= 'A';
            // 카드의 좌표 기록
            if (cards[num].one.r == -1 ) {
                cards[num].one.r = r;
                cards[num].one.c = c;
            } else {
                cards[num].two.r = r;
                cards[num].two.c = c;
                cards[num].findMidPoints();
                cardCnt++;
            }
        }
    }
}

// 직선 상의 두 점 사이에 . 이 아닌 값이 있으면 false 리턴
bool canPass(Point start, Point end) {
    if (start.r == end.r) {
        if (start.c > end.c) {
            int t = start.c;
            start.c = end.c;
            end.c = t;
        }
        for (int c = start.c + 1; c < end.c; ++c) {
           if (board[start.r][c] != '.') {
               return false;
           }
        }
        return true;
    } else {
        if (start.r > end.r) {
            int t = start.r;
            start.r = end.r;
            end.r = t;
        }
        for (int r = start.r + 1; r < end.r; ++r) {
           if (board[r][start.c] != '.') {
               return false;
           }
        }
        return true;
    }
}

// int -> string 변환, 0 -> "A"
string convert(int i) {
    return string(1,'A'+i);
}

void matchCards(int i) {
    // 결과 순서 기록
    answer += convert(i);
    // 보드에서 카드 지우기
    board[cards[i].one.r][cards[i].one.c] = '.';
    board[cards[i].two.r][cards[i].two.c] = '.';
    // 카드 정보 삭제
    cards[i] = CardInfo();
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int _m, int _n, vector<string> _board) {
    board = _board;
    m = _m;
    n = _n;
    init();
    
    for (int i = 0; i < 27; ++i) {
        if (cards[i].one.r == -1) continue;
        
        if (cards[i].direct) {
            if (canPass(cards[i].one, cards[i].two)) {
                matchCards(i);
                i = -1; // 알파벳 빠른 순으로 다시 A부터 검사하기 위해
            }
        } else { 
            // 꺾인점 기준으로 두 직선 사이에 장애물 없는지, 꺾인점도 장애물이 아닌지
            if (canPass(cards[i].one, cards[i].mid1)
                 && canPass(cards[i].mid1, cards[i].two)
                    && board[cards[i].mid1.r][cards[i].mid1.c] == '.') {
                matchCards(i);
                i = -1;
            } else if (canPass(cards[i].one, cards[i].mid2)
                        && canPass(cards[i].mid2, cards[i].two)
                        && board[cards[i].mid2.r][cards[i].mid2.c] == '.') {
                matchCards(i);
                i = -1;
            }
        }
    }
    
    // 모든 카드를 제거했는지
    if (answer.length() != cardCnt) {
        return "IMPOSSIBLE";
    } else return answer;
}
