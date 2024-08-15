#include<vector>
#include<queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;

    int n = maps.size() - 1;
    int m = maps[0].size() - 1;

    int dx[4] = { 0,0, -1, 1 };
    int dy[4] = { -1,1,0,0 };

    vector<vector<int>> dist(n + 1, vector<int>(m + 1, -1));
    queue<pair<int, int>> q;

    dist[0][0] = 1;
    q.push(make_pair(0, 0));


    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx > m || ny > n)
                continue;

            if (maps[ny][nx] == 0)
                continue;

            if (dist[ny][nx] != -1)
                continue;

            dist[ny][nx] = dist[y][x] + 1;

            if (nx == m && ny == n)
                return dist[ny][nx];

            q.push(make_pair(ny, nx));
        }
    }
    return -1;
}