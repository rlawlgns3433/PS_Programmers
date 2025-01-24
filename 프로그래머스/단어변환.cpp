#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 500;
vector<string> visited;

vector<string> GetCandidateTarget(string current, const vector<string>& words)
{
    visited.push_back(current);

    vector<string> target;
    for (auto word : words)
    {
        int diff = 0;
        for (int i = 0; i < word.size(); ++i)
        {
            if (current[i] != word[i])
                diff++;
        }

        if (diff == 1)
            target.push_back(word);
    }

    return target;
}

void dfs(string cur, string target, const vector<string>& words, int n)
{
    if (cur == target)
    {
        answer = min(answer, n);
    }

    vector<string> candidate = GetCandidateTarget(cur, words);


    for (auto c : candidate)
    {
        if (find(visited.begin(), visited.end(), c) != visited.end())
            continue;
        dfs(c, target, words, n + 1);
    }
    visited.erase(find(visited.begin(), visited.end(), cur));
}


int solution(string begin, string target, vector<string> words) {

    dfs(begin, target, words, 0);

    if (answer == 500)
        return 0;

    return answer;
}