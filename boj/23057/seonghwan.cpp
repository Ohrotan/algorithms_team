#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n;
int ans;
int totalCnt;
unordered_map<int, int> map;
vector<int> vec;

void dfs(int cnt, int sum) {

	if (map[sum] == 0) {
		map[sum]++;
		totalCnt++;
	}
	if (cnt == n) return;

	dfs(cnt + 1, sum + vec[cnt]);
	dfs(cnt + 1, sum);
}


int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}

	int totalSum = 0;

	for (int i = 0; i < n; i++) {
		totalSum += vec[i];
	}

	dfs(0, 0);

	cout << (totalSum - totalCnt + 1);

	return 0;
}