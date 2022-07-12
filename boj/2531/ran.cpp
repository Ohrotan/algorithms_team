#include <iostream>
#include <vector>

using namespace std;
int dishCnt, kindCnt, eatingCnt, coupon;
vector<int> dishes;
int sushiCnt[3001] = {0,};
int startPos = 0;
int endPos = 0;
int curKind = 0;
int maxKind = 0; // eatingCnt + 1 이하 && kindCnt 이하
int possibleMax = 0;
bool hasCoupon = false;

void sol() {
    while (startPos < dishCnt - 1) {
        sushiCnt[dishes[startPos]]--;
        if (sushiCnt[dishes[startPos]] == 0) {
            curKind--;
            if (dishes[startPos] == coupon) {
                hasCoupon = false;
            }
        }
        startPos++;

        endPos++;
        endPos = endPos%dishCnt;
        sushiCnt[dishes[endPos]]++;
        if (sushiCnt[dishes[endPos]] == 1) {
            curKind++;
            if (dishes[endPos] == coupon) {
                hasCoupon = true;
            }
        }

        if (maxKind < curKind + !hasCoupon) {
            maxKind = curKind + !hasCoupon;
        }
        if (maxKind == possibleMax) {
            break;
        }
    }
}

void init() {
    possibleMax = min(eatingCnt + 1, kindCnt);
    endPos = startPos + eatingCnt;
    for (int i = 0; i < endPos; ++i) {
        sushiCnt[dishes[i]]++;
        if (sushiCnt[dishes[i]] == 1) {
            curKind++;
            if (dishes[i] == coupon) {
                hasCoupon = true;
            }
        }
    }
    endPos--;
    if (maxKind < curKind + !hasCoupon) {
        maxKind = curKind + !hasCoupon;
    }
}

void input() {
    cin >> dishCnt >> kindCnt >> eatingCnt >> coupon;
    dishes.reserve(dishCnt);
    int tmp;
    for (int i = 0; i < dishCnt; ++i) {
        cin >> tmp;
        dishes.push_back(tmp);
    }
}

int main() {
    input();
    init();
    sol();
    cout << maxKind << endl;
}
