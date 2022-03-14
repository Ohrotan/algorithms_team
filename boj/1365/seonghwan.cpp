/*
1. 메모리 : 3052 KB, 시간 : 40 ms
2. 전선이 꼬이지 않아야 한다는 말은 상대편 전봇대의 번호가 무조건 증가하는 방향으로 연결되어야 한다는 뜻
3. 따라서 증가하다가 감소하는 포인트의 숫자는 무시한다.
4. 하지만 감소한 지점에서부터 차례대로 증가하는 수열을 구했을 때가 더 길 수 있기 때문에
		(=연결 할 수 있는 전선이 더 많을 수 있기 때문에) 마냥 무시할 수는 없는 법
5. 따라서 이중 for문으로 증가하는 수열이 가장 긴 수열을 고를 수 있다
		(1중 for문 : 시작하는 전봇대 지점, 2중 for문 : 시작 전봇대 지점으로부터 증가하는 수열 구하기)
6. 하지만 n^2 시간 복잡도로 100,000 * 100,000의 연산을 해야할 수 있으므로 안됨.
7. 증가하다가 감소하는 수를 만났을 때 만약 앞에서 현재 마주친 수보다 크고 직전에 만난 수보다는 작은 수들을 아예
		벡터에 넣지 않았다면 현재 마주친 수열을 벡터에 집어넣을 수 있고, 그 결과 더 긴 수열을 가질 수 있기 때문에
		이분탐색을 통해 벡터에서 현재 마주친 수열보다 작은 수들 중 가장 큰 수의 다음 index에 현재 마주친 수를
		위치시킨다.(만약 이 수를 넣었을 경우 어떻게 될지를 보기 위함) -> 이분탐색이므로 logn의 시간복잡도가 곱해짐
8. 위 내용을 기둥의 갯수만큼 반복하면 n * logn의 시간 복잡도로 시간초과 안남
9. 위 작업을 하게되면 전선의 오름차순 중 가장 긴 수열이 나오진 않는다(7번에 만약에라는 가정으로 현재 검사중인
		기둥 번호를 증가하는 기둥 수열의 중간에 임의로 삽입을 해 버렸기 때문). 하지만 수열의 길이를 보고자 하는
		것이므로 길이만 보기위함이면 상관없음
10. 이렇게 증가하는 방향으로 연결된 전선들 중 최대 갯수를 찾으면 전체 전선의 길이에서 이걸 빼 주면 잘라야 할 전선이 됨
*/

#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(vector<int>* increaseNumber, int inputNumber);

int main() {

	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> pole;				//마주보는 위치의 전봇대 번호를 순서대로
	vector<int> increaseNumber;		//전선이 안꼬이려면 무조건 증가하는 번호에 연결되어야 하기에
									//상대편 전봇대 중 증가하는 전봇대만 고름

	int poleCount = 0;
	int inputPoleNumber;

	cin >> poleCount;

	for (int i = 0; i < poleCount; i++) {
		cin >> inputPoleNumber;
		pole.push_back(inputPoleNumber);
	}

	//맨 처음 연결된 전선은 증가전봇대 벡터에 집어넣는다.
	increaseNumber.push_back(pole[0]);

	for (int i = 1; i < poleCount; i++) {
		//증가하는 번호의 전봇대 목록의 마지막 수(가장 큰 수)보다 크면 그 뒤에 넣고
		if (pole[i] >= increaseNumber[increaseNumber.size() - 1]) {
			increaseNumber.push_back(pole[i]);
		}
		//가장 큰 수 보다 작으면 본인이 들어갈 위치의 인덱스를 찾아서 삽입
		else {
			int poleIndex = BinarySearch(&increaseNumber, pole[i]);
			increaseNumber[poleIndex] = pole[i];
		}
	}
	//위 for문을 하게되면 실제 전봇대가 증가하는 방향의 수열이 담기진 않지만 그와 동일한 길이를 구할 수 있음

	cout << (poleCount - increaseNumber.size());	//잘라야 할 전선

	return 0;
}

int BinarySearch(vector<int>* increaseNumber, int inputNumber) {
	int firstIndex = 0;
	int lastIndex = increaseNumber->size() - 1;
	int middleIndex = firstIndex;
	int index = firstIndex;

	//맨 앞보다 더 앞, 맨 뒤보다 더 뒤에 존재할 경우 생각
	if (increaseNumber->at(0) > inputNumber)
		return 0;
	else if (increaseNumber->at(lastIndex) < inputNumber)
		return lastIndex + 1;

	//이진탐색으로 pole[i](=inputNumber)가 들어가야 할 index값을 반환
	while (firstIndex + 1 != lastIndex) {
		middleIndex = (firstIndex + lastIndex) / 2;
		if (increaseNumber->at(middleIndex) > inputNumber) {
			lastIndex = middleIndex;
		}
		else if (increaseNumber->at(middleIndex) < inputNumber) {
			firstIndex = middleIndex;
		}
	}

	return lastIndex;
}