#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> mp;

    for (string it : participant)
    {
        if (mp.find(it) == mp.end())
        {
            mp.insert(make_pair(it, 1));
        }
        else mp[it]++;
    }

    for (string it : completion)
    {
        mp[it]--;
    }

    for (string it : participant)
    {
        if (mp[it] > 0)
        {
            answer = it;
            break;
        }
    }
    return answer;
}