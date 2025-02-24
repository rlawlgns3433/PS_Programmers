#include <string>
#include <vector>
using namespace std;

bool operator>=(string& lhs, string& rhs)
{
    int size = lhs.size();
    int i = -1;
    while (true)
    {
        i++;
        if (i == size)
            break;

        if (lhs[i] == rhs[i])
            continue;
        else if (lhs[i] > rhs[i])
            return true;
        else
            return false;
    }

    return true;
}

int solution(string t, string p) {
    int answer = 0;

    int tSize = t.size();
    int pSize = p.size();
    vector<string> v;

    for (int i = 0; i < tSize - pSize + 1; ++i)
    {
        string temp;

        for (int j = i; j < i + pSize; ++j)
        {
            temp.push_back(t[j]);
        }

        v.push_back(temp);
    }

    for (int i = 0; i < tSize - pSize + 1; ++i)
    {
        if (p >= v[i])
            answer++;
    }

    return answer;
}