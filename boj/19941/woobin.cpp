#include <iostream>
#include <string>
using namespace std;

int N;
int K;
int answer;
string line;

int main() {
    cin >> N >> K;
    cin >> line;
    
    for(int i = 0; i < N; i++) {
        char characterAtIndex = line.at(i);
        if (characterAtIndex == 'P') {
            int start = i - K;
            int end = i + K;
            
            for (int j = start; j <= end; j++) {
                if (j < 0 || j >= N) {
                    continue;
                }
                
                if (line.at(j) == 'H') {
                    line.at(j) = 'X';
                    answer++;
                    break;
                }
            }
        }
    }
    
    cout << answer << "\n";
    return 0;
}
