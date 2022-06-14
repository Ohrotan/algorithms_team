//  먼저 치환 후, 큰수부터 9, 8, 7...
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
	int N;

	cin >> N;
	vector<string> input(N);
	unordered_map<char, int> map;
	int answer = 0;

	// 초기화
	for (char i = 'A'; i <= 'Z'; ++i) {
		map[i] = 0;
	}

	//  입력 받기
	for (int i = 0; i < N; i += 1) {
		string s = "";
		cin >> s;
		input[i] = s;
	}

	// 각 알파벳에 곱해지는 수 채우기
	for (int i = 0; i < N; i += 1) {
		string s = input[i];
		int digit = 1;
		for (int j = s.size()-1; j >= 0; --j) {
			map[s[j]] = map[s[j]] + digit;
			digit = digit * 10;
		}
	}

	for (int mul = 9; mul >= 1; --mul) {  // 최대 9~ 최소 1로채워줌
		char maxC = 'A';
		int maxVal = 0;
		// 큰 수부터 정렬
		for (pair<char, int> p : map) {
			if (p.second > maxVal) {
				maxC = p.first;
				maxVal = p.second;
			}
		}
		map[maxC] = 0;
		// cout << "알파벳: " << maxC << " " << "  곱해지는 수: " << maxVal << "\t* " << mul << endl;
		answer += maxVal * mul;
	}
	cout << answer;
	return 0;
}
