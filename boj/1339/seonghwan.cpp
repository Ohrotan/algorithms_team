/*
- 그리디로 푸는법은 도무지 떠오르지 않음..
- 십진수에서 자릿수끼리 분리해서 더하기로 표현할 수 있다는 점을 이용함.

*/
#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int n;
int sum = 0;
unordered_map<char, int> cntMap;		//문제에서 주어진 문자형 숫자를 자릿수끼리 분리& 알파벳끼리 더해서 조합하여 어느 알파벳에 곱해진 상수가 얼마나되는지 나타냄
vector<pair<int, char>> vec;			//위 맵에서의 알파벳과 그에 해당하는 상수를 저장(정렬을 위해 상수를 first에 둠)

int main() {
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = temp.length() - 1; j >= 0; j--) {	//문자의 맨 첫번째 자리부터 계산
			int square = temp.length() - 1 - j;	//문자에 곱해진 상수가 10의 몇제곱인지 계산.(예로들어 셋째자리면 square가 2가 되고 나중에 num은 100이 됨
			int num = 1;
			for (int k = 0; k < square; k++) {
				num *= 10;
			}
			cntMap[temp[j]] += num;			//기존에 알파벳에 곱해진 상수에다가 추가 해주기(곱셈의 결합법칙 이용)
		}
	}

	for (int i = 'A'; i <= 'Z'; i++) {
		vec.push_back({ cntMap[(char)i], (char)i });	//어떤 알파벳이 주어질지 모르니 일단 걍 싹다 벡터에 넣고
	}

	sort(vec.begin(), vec.end());				//곱해진 상수가 작은 순서대로 소트함(구조체 비교함수 만드는법 까먹어서 내림차순 정렬 까먹음;;)

	int zeroPoint;						//vec의 맨 뒤에서 차례대로 조사했을때 0이 나오는 시점. 이 시점에 해당하는 알파벳(vec[i].second)은 문제에서 안주어졌던거임

	for (int i = vec.size() - 1; i >= 0; i--) {		//zeroPoint 찾는 부분
		if (vec[i].first == 0) {
			zeroPoint = i;
			break;
		}
	}

	int coefficient = 9;
	for (int i = vec.size() - 1; i > zeroPoint; i--) {	//곱해진 상수가 큰 순서대로 계수를 붙여줌. 9부터 8, 7, 6, .... 이렇게
		sum += vec[i].first * coefficient;		//그리고 계수랑 상수를 곱해서 총 합에 더함
		coefficient--;
	}

	cout << sum;

	return 0;

}
