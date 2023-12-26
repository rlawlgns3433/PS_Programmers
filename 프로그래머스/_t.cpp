#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int r = park.size();
    int c = park[0].size();
    int start_x, start_y;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (park[i][j] == 'S')
            {
                start_x = j, start_y = i;
                break;
            }
        }
    }

    int sz_r = routes.size();
    int sz_rr = routes[0].size();
    int x = 0, y = 0;
    for (int i = 0; i < sz_r; i++) {
        char dir = routes[i][0];
        int cnt = routes[i][2] - '0';
        bool b = false;
        if (dir == 'W') x = start_x - cnt;
        else if (dir == 'E') x = start_x + cnt;
        else if (dir == 'N') y = start_y - cnt;
        else y = start_y + cnt;

        // 1번 조건
        if (x < 0){ x += cnt; continue;}
        else if (y < 0) { y += cnt; continue; }
        else if (x >= c) { x -= cnt; continue; }
        else if (y >= r) { y -= cnt; continue; }
        
        // 2번 조건
        for (int j = 1; j <= cnt; j++)
        {
            switch (dir)
            {
            case 'W':
                if (park[start_y][start_x - j] == 'X') {
                    x = start_x;
                    b = true;
                }
                break;
            case 'E':
                if (park[start_y][start_x + j] == 'X') {
                    x = start_x;
                    b = true;
                }
                break;
            case 'N':
                if (park[start_y - j][start_x] == 'X') {
                    y = start_y;
                    b = true;
                }
                break;
            case 'S':
                if (park[start_y + j][start_x] == 'X') {
                    y = start_y;
                    b = true;
                }
                break;
            }
            if (b) break;
        }
        if (b) continue;

        start_x = x, start_y = y;
    }

    answer.push_back(y);
    answer.push_back(x);
    return answer;
}

int main()
{
    vector<string> s, routes;
    s.push_back("OSO");
    s.push_back("O00");
    s.push_back("OXO");
    s.push_back("OOO");
    routes.push_back("E 2");
    routes.push_back("S 3");
    routes.push_back("W 1");
    for (int i : solution(s, routes))
    {
        cout << i << ' ';
    }
}