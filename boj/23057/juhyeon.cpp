
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int ans, N;
unordered_map<int, int> poss;
vector<int> v;

void dfs(int cnt, int before)
{
    if (cnt == N)
        return;
    else if (poss[v[cnt] + before] == 0)
    {
        poss[v[cnt] + before]++;
        ans++;
    }
    dfs(cnt + 1, before + v[cnt]);
    dfs(cnt + 1, before);
}
int main()
{
    int M = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
        M += v[i];
    }
    dfs(0, 0);
    cout << M-ans << endl;

    return 0;
}
