#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
int numberOfCharacter[26];
int answer;
string input[10];

bool compare(const int a, const int b) {
    return a > b;
}

int main() {
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        string temp {""};
        cin >> temp;
        input[i] = std::move(temp);
    }
    
    for(int i = 0; i < N; i++) {
        int length = input[i].length();
        for(int j = 0; j < length; j++) {
            int indexOfCharacter = input[i].at(j) - 'A';
            numberOfCharacter[indexOfCharacter] += pow(10, length - 1 - j);
        }
    }
    
    std::sort(numberOfCharacter, numberOfCharacter + 26, compare);
    
    int multiplingNumber = 9;
    for(int i = 0; i < 26; i++) {
        if(numberOfCharacter[i] != 0) {
            answer += numberOfCharacter[i] * multiplingNumber--;
        } else {
            break;
        }
    }
    
    cout << answer << "\n";
    return 0;
}
