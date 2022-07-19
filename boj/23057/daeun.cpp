#include <iostream>
#include <set>

using namespace std;

#define MAX_N 20

int N, M;
int num[MAX_N + 1];
void Input_Data() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
        M += num[i];
    }
}

// int ch[MAX_N + 1] = {0, };
set<int> res;
void dfs(int l, int sum) {
    if (l == N) {
        res.insert(sum);
        // cout << "sum: " << sum << '\n';
        return;
    }
    dfs(l+1, sum);
    dfs(l+1, sum + num[l]);
}

int Solve() {
    dfs(0, 0);
    return M - res.size() + 1;
}
 
int main(void)
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input_Data();

    cout << Solve() << '\n';

    return 0;
}
