#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<int, string> map1;
    map<string, int> map2;

    for (int i = 0; i < players.size(); ++i)
    {
        map1[i] = players[i];
        map2[players[i]] = i;
    }

    for (int i = 0; i < callings.size(); ++i)
    {
        int index = map2[callings[i]];
        string nameToChange = map1[index - 1];

        map1[index - 1] = callings[i];
        map1[index] = nameToChange;

        map2[callings[i]] = index - 1;
        map2[nameToChange] = index;
    }

    for (auto& e : map1)
    {
        answer.emplace_back(e.second);
    }

    return answer;
}