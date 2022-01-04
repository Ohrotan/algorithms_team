#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    int makeMoneyCount[100001];

    makeMoneyCount[0] = 1;
    for (int i = money[0]; i <= n; i += money[0])
    {
        makeMoneyCount[i] = 1;
    }

    for (int i = 1; i < money.size(); i++)
    {
        for (int j = money[i]; j <= n; j++)
        {
            makeMoneyCount[j] += makeMoneyCount[j - money[i]] % 1000000007;
        }
    }
    answer = makeMoneyCount[n];
    return answer;
}