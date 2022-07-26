#include <iostream>

using namespace std;

typedef long long ll;
ll a, b, c;

int DivideConqour(int a, int b) {
	if (b == 1) return a % c;
	ll _c = DivideConqour(a, b / 2);

	_c = (_c * _c) % c;

	if (b & 1 != 0) {
		_c = (_c * a) % c;
	}

	return _c;
}



int main() {

	cin >> a >> b >> c;

	int result = DivideConqour(a, b);

	cout << result;

}


/*
아래는 시간초과 코드.



#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long ll;

ll a, b, c;
unordered_map<ll, ll> map;

int DevideConqour(ll depth) {

	if (depth == 1) {
		return a % c;
	}
	else {
		int res1, res2;
		if (map[depth / 2] == 0) {
			map[depth / 2] = DevideConqour(depth / 2);
		}
		if (map[depth - depth / 2] == 0) {
			map[depth - depth / 2] = DevideConqour(depth - depth / 2);
		}

		res1 = map[depth / 2];
		res2 = map[depth - depth / 2];

		return res1 * res2 % c;
	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> a >> b >> c;
	int ans =  DevideConqour(b);

	cout << ans;

}



*/