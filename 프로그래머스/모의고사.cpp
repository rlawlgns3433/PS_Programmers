#include <string>
#include <vector>
using namespace std;

bool TestFirst(int i, int ans)
{
    if ((i % 5) + 1 == ans)
        return true;
    return false;
}

bool TestSecond(int i, int ans)
{
    if (i % 2 == 0 && ans == 2)
        return true;
    // 1 3 4 5
    if (i % 8 == 1 && ans == 1)
        return true;
    else if (i % 8 == 3 && ans == 3)
        return true;
    else if (i % 8 == 5 && ans == 4)
        return true;
    else if (i % 8 == 7 && ans == 5)
        return true;

    return false;
}

bool TestThird(int i, int ans)
{
    // 33 11 22 44 55
    if (i % 10 < 2 && ans == 3)
        return true;
    else if (i % 10 >= 2 && i % 10 < 4 && ans == 1)
        return true;
    else if (i % 10 >= 4 && i % 10 < 6 && ans == 2)
        return true;
    else if (i % 10 >= 6 && i % 10 < 8 && ans == 4)
        return true;
    else if (i % 10 >= 8 && i % 10 < 10 && ans == 5)
        return true;
    return false;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> answerCount(3, 0);

    for (int i = 0; i < answers.size(); ++i)
    {
        if (TestFirst(i, answers[i])) answerCount[0]++;
        if (TestSecond(i, answers[i])) answerCount[1]++;
        if (TestThird(i, answers[i])) answerCount[2]++;
    }

    int maxValue = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (maxValue < answerCount[i])
        {
            answer.clear();
            answer.push_back(i + 1);
            maxValue = answerCount[i];
        }
        else if (maxValue == answerCount[i])
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}