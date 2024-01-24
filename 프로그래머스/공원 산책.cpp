#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;

    for (int i = 0; i < park.size(); ++i)
    {
        for (int j = 0; j < park[i].size(); ++j)
        {
            if (park[i][j] == 'S')
            {
                // 시작 행, 열을 저장
                answer.push_back(i);
                answer.push_back(j);
                break;
            }
        }
    }
    // 북 동 서 남
    int dx[] = { 0, 1, 0, -1 };
    int dy[] = { -1, 0, 1, 0 };

    for (int i = 0; i < routes.size(); ++i)
    {
        string direction = routes[i].substr(0, 1);
        int moveCnt = stoi(routes[i].substr(2));

        if (direction == "N")
        {
            int k = moveCnt;
            if (answer[0] + dy[0] < 0) continue;
            for (int j = 1; j <= moveCnt; ++j)
            {
                if (answer[0] + j * dy[0] < 0 || park[answer[0] + j * dy[0]][answer[1]] == 'X') k--;
            }
            if (moveCnt == k)
            {
                answer[0] += dy[0] * moveCnt;
            }
        }
        else if (direction == "S")
        {
            int k = moveCnt;
            if (answer[0] + dy[2] > park.size() - 1) continue;
            for (int j = 1; j <= moveCnt; ++j)
            {
                if (answer[0] + j * dy[2] > park.size() - 1 || park[answer[0] + j * dy[2]][answer[1]] == 'X') k--;
            }
            if (moveCnt == k)
            {
                answer[0] += dy[2] * moveCnt;
            }
        }
        else if (direction == "W")
        {
            int k = moveCnt;
            if (answer[1] + dx[3] < 0) continue;
            for (int j = 1; j <= moveCnt; ++j)
            {
                if (answer[1] + j * dx[3] < 0 || park[answer[0]][answer[1] + j * dx[3]] == 'X') k--;
            }
            if (moveCnt == k)
            {
                answer[1] += dx[3] * moveCnt;
            }
        }
        else if (direction == "E")
        {
            int k = moveCnt;
            if (answer[1] + dx[1] > park[0].size() - 1) continue;
            for (int j = 1; j <= moveCnt; ++j)
            {
                if (answer[1] + j * dx[1] > park[0].size() - 1 || park[answer[0]][answer[1] + j * dx[1]] == 'X') k--;
            }
            if (moveCnt == k)
            {
                answer[1] += dx[1] * moveCnt;
            }
        }
    }

    return answer;
}