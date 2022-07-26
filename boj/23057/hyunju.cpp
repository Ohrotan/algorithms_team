// 최대 2^20
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <math.h>
#include <thread>

using namespace std;

int main()
{
	// 입력 받기
	int N;
	cin >> N;
	vector<int> nums;
	int maxSum = 0;
	for (int i = 0; i < N; ++i) {
		int num;
		cin >> num;
		maxSum += num;
		nums.push_back(num);
	}

	unordered_set<int> set;
	int cnt = 0;

	for (int i = 0; i < pow(2, N); ++i) {
		int sum = 0;
		for (int j = 0; j < N; ++j) {
			sum += nums[j] * ((i >> j) & 1);
		}
		if (set.count(sum) == 0) {
			++cnt;
			set.insert(sum);
		}
	}

	cout << maxSum - cnt + 1;

	return 0;
}
