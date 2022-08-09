#include <iostream>

using namespace std;

int n = 0;
int m = 0;
int sum = 0;
int ans = 0;

int lectures[100'000] = { 0, };

bool CheckPossible(int mid) {
	int cnt = 0;
	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum += lectures[i];

		if (sum > mid) {
			sum = lectures[i];
			cnt++;
		}
	}

	cnt++;

	if (cnt > m) {
		return false;
	}
	else {
		return true;
	}
}

void BinarySearch(int min, int max) {
	int mid = (min + max) / 2;
	bool isPossible = false;
	if (mid <= min) {
		ans = max;
		return;
	}

	isPossible = CheckPossible(mid);

	if (isPossible == false) {
		BinarySearch(mid, max);
	}
	else {
		BinarySearch(min, mid);
	}

}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		lectures[i] = temp;
		sum += lectures[i];
	}


	BinarySearch(0, sum);

	cout << ans;

}
