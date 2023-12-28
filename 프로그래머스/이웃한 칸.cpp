#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
  int answer = 0;
  string target = board[h][w];
  int n = board.size();
  int dy[4] = {1, -1, 0, 0};
  int dx[4] = {0, 0, 1, -1};

  for (int i = 0; i < 4; i++) {
    int ny = h + dy[i];
    int nx = w + dx[i];

    if ((nx >= 0 && nx < n) && (ny >= 0 && ny < n)) {
      if (board[ny][nx] == target) {
        answer++;
      }
    }
  }

  return answer;
}