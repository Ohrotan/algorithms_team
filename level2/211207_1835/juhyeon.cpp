#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isRight(int t, int diff, char cmds) {
  if (cmds == '=') {
    return diff == t;
  } else if (cmds == '>') {
    return diff < t;

  } else {
    return diff > t;
  }
}
int solution(int n, vector<string> data) {
  int    answer = 0;
  string friends = "ACFJMNRT";
  do {
    bool flag = true;
    for (int i = 0; i < n; i++) {
      char who = data[i][0];
      char target = data[i][2];
      int  diff = data[i][4] - '0';
      char cmds = data[i][3];
      int  widx = friends.find(who);
      int  tidx = friends.find(target);
      if (isRight(abs(tidx - widx)-1, diff, cmds))
        continue;
      else {
        flag = false;
        break;
      }
    }
    if (flag)
      answer++;
  } while (next_permutation(friends.begin(), friends.end()));

  return answer;
}