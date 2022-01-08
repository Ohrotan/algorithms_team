#include <vector>
using namespace std;

int solution(int n, vector<int> apts, int w)
{
    int res = 0;
    apts.insert(apts.begin(), -w); // 처음의 빈공간 계산을 위해 
    apts.push_back(n+w+1); // 마지막 빈공간 계산을 위해
    for (int i = 1; i < apts.size(); ++i) {
        int blank = apts[i] - apts[i-1] - w - w - 1; // 두 기지국 사이의 빈공간
        int cnt = 0; // 필요한 기지국수
        if (blank > 0) {
            cnt = blank / (w+w+1);
            if (blank % (w+w+1) > 0) {
                cnt++;
            }
        }
        res += cnt;
    }
    
    return res;
}
