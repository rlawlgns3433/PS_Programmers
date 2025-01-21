#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = 0;

    vector<pair<int, int>> v;

    int parkRowSize = park.size();
    int parkColSize = park[0].size();

    for (int i = 0; i < parkRowSize; ++i)
    {
        for (int j = 0; j < parkColSize; ++j)
        {
            if (park[i][j] == "-1")
                v.push_back(make_pair(i, j));
        }
    }

    bool b = false;

    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < mats.size(); ++j)
        {
            int y = v[i].first;
            int x = v[i].second;
            int k = 0;
            b = false;
            for (k = 0; k < mats[j]; ++k)
            {
                if (y + k >= parkRowSize)
                    break;

                for (int l = 0; l < mats[j]; ++l)
                {
                    if (x + l >= parkColSize)
                    {
                        b = true;
                        break;
                    }

                    if (park[y + k][x + l] != "-1")
                    {
                        b = true;
                        break;
                    }
                }

                if (b)
                    break;
            }

            if (k == mats[j])
                answer = max(answer, mats[j]);
        }
    }

    if (answer == 0)
        answer = -1;

    return answer;
}