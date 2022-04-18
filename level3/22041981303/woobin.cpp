#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> table;
stack<pair<int, int>> trashCan; // index, 값
auto currentIter = table.begin();
int currentIndex = 0;

void commandTyped(string cmd) {
	if(cmd.at(0) == 'C') { // erase 
		trashCan.push({currentIndex, *currentIter});
		if(currentIndex == static_cast<int>(table.size()) - 1) {
			currentIndex--;
		}
		table.erase(currentIter);
	} else if(cmd.at(0) == 'Z') {
		int idx = trashCan.top().first;
		int value = trashCan.top().second;
		table.insert(table.begin() + idx, value);
		trashCan.pop();
		if(idx < currentIndex) {
			currentIndex++;
		}
	} else {
		int movingIndex = stoi(cmd.substr(2));
		currentIndex = cmd.at(0) == 'U' ?  currentIndex - movingIndex : currentIndex + movingIndex;
	}
}

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
	answer.assign(n, 'O');
	currentIndex = k;
	for(int i = 0; i < n; i++) {
		currentIter = table.begin() + currentIndex;
		table.push_back(i);
	}

	for(auto e : cmd) {
		commandTyped(e);
	}

	while(!trashCan.empty()) {
		int removedIndex = trashCan.top().first;
		trashCan.pop();
		answer.at(removedIndex) = 'X';
	}

    return answer;
}
