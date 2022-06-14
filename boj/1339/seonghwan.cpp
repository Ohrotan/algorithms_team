#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int n;
int sum = 0;
unordered_map<char, int> cntMap;
vector<pair<int, char>> vec;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = temp.length() - 1; j >= 0; j--) {
			int square = temp.length() - 1 - j;
			int num = 1;
			for (int k = 0; k < square; k++) {
				num *= 10;
			}
			cntMap[temp[j]] += num;
		}
	}

	for (int i = 'A'; i <= 'Z'; i++) {
		vec.push_back({ cntMap[(char)i], (char)i });
	}

	sort(vec.begin(), vec.end());

	int zeroPoint;

	for (int i = vec.size() - 1; i >= 0; i--) {
		if (vec[i].first == 0) {
			zeroPoint = i;
			break;
		}
	}

	int coefficient = 9;
	for (int i = vec.size() - 1; i > zeroPoint; i--) {
		sum += vec[i].first * coefficient;
		coefficient--;
	}

	cout << sum;

	return 0;

}
