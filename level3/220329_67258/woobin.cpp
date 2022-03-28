#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
	unordered_map<string, int> countMap;

	int startIndex = 0; // while문 돌면서 증감할 시작점
	int endIndex = 0; // while문 돌면서 증감할 끝점
	int totalNumOfGems = 0; // 보석 종류의 수
	int currentNumofGems = 0; // while문 돌면서 현재까지 count한 보석 수
	int answerStartIndex = 0; // 정답에 넣을 시작점
	int answerEndIndex = 0; // 정답에 넣을 끝점
	int distance = 100001; // 시작점과 끝점 사이의 길이

	for(auto &&e : gems) {
		if(countMap.find(e) == countMap.end()) {
			// map안에 key 없을 시 초기 값 0으로 insert
			countMap.insert({e, 0});
		}
	}

	totalNumOfGems = static_cast<int>(countMap.size());

	while(true) {
		// 끝점까지 다 셌으면 이제 시작점에서 하나씩 증가하면서 distance를 줄인다
		if(currentNumofGems == totalNumOfGems) {
			if(endIndex - startIndex < distance) {
				distance = endIndex - startIndex;
				answerEndIndex = endIndex;
				answerStartIndex = startIndex;
			}

			string startCurrentGem = gems[startIndex];
			if(countMap.at(startCurrentGem) == 1) {
				currentNumofGems--;
			}
			countMap.at(startCurrentGem)--;
			startIndex++;		

		} else {
			// 끝점부터 돈다 반복문 처음엔 이쪽만 돔
			if(endIndex == static_cast<int>(gems.size())) {
				break;
			}

			string endCurrentGem = gems[endIndex];
			if(countMap.at(endCurrentGem) == 0) {
				currentNumofGems++;
			}
			countMap.at(endCurrentGem)++;
			endIndex++;
		}
	}

	answer.push_back(answerStartIndex + 1);
	answer.push_back(answerEndIndex);

    return answer;
}
