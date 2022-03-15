#include <iostream>
#include <vector>

using namespace std;

int lowerBound(vector<int> v, int num) {
	// 이분 탐색으로 값을 넣을 위치 반환
	int low = 0, high = v.size() - 1;

	while (low < high) {
		int mid = (low + high) / 2;
		if (v[mid] > num)
			high = mid;
		else
			low = mid + 1;
	}
	return high;
}

int main()
{
	int n, num;
	cin >> n;
	vector<int> v;
	v.push_back(-1);  // 코드의 편의성
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num > v[v.size() - 1])
			v.push_back(num);
		else
			v[lowerBound(v, num)] = num;
	}
	cout << n - v.size() + 1;

	return 0;
}
