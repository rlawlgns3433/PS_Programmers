#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2,
                vector<string> goal) {
  string answer = "";

  int size1 = cards1.size();
  int size2 = cards2.size();
  int goal_size = goal.size();

  int cnt = 0;
  int p1 = 0, p2 = 0;

  while (p1 + p2 != goal_size) {
    if (cnt > 10) return "No";

    if (p1 < size1 && cards1[p1] == goal[p1 + p2] ) {
      p1++;
      cnt = 0;
    }
    if (p2 < size2 && cards2[p2] == goal[p1 + p2] ) {
      p2++;
      cnt = 0;
    }
    cnt++;
  }

  return "Yes";
}

int main() {

    vector<string> cards1 = {"i", "water", "drink"};
    vector<string> cards2 = {"want", "to"};
    vector<string> goal = {"i", "want", "to", "drink", "water"};

    cout << solution(cards1, cards2, goal);

}