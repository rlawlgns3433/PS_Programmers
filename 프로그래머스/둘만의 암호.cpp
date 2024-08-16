#include <string>
#include <vector>
using namespace std;

bool IsSkipped(char c, string skip)
{
    for (int i = 0; i < skip.size(); ++i)
    {
        if (skip[i] == c)
            return true;
    }
    return false;
}

char GetCharacter(char c, int index, string skip)
{
    for (int i = 0; i < index; ++i)
    {
        c++;

        if (c >= 123)
        {
            c = c % 123 + 97;
        }

        if (IsSkipped(c, skip))
        {
            i--;
        }
    }

    return c;
}

string solution(string s, string skip, int index) {
    string answer = "";

    for (int i = 0; i < s.size(); ++i)
    {
        answer += GetCharacter(s[i], index, skip);
    }

    return answer;
}