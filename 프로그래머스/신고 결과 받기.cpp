#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int getEmptyCharacterIndex(const string& str)
{
    int i = 0;
    while (str[i] != ' ')
        ++i;

    return i;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {

    unordered_map<string, vector<string>> reportMap;
    unordered_map<string, vector<string>> reportedMap;

    for (int i = 0; i < id_list.size(); ++i)
    {
        reportMap.insert(make_pair(id_list[i], vector<string>()));
        reportedMap.insert(make_pair(id_list[i], vector<string>()));
    }

    for (int i = 0; i < report.size(); ++i)
    {
        int empty = getEmptyCharacterIndex(report[i]);
        string first = report[i].substr(0, empty);
        string second = report[i].substr(empty + 1);

        reportMap[first].push_back(second);
        reportedMap[second].push_back(first);
    }

    vector<int> ans;
    ans.resize(id_list.size(), 0);
    unordered_map<string, int> answer;

    for (int i = 0; i < id_list.size(); ++i)
    {
        sort(reportedMap[id_list[i]].begin(), reportedMap[id_list[i]].end());
        reportedMap[id_list[i]].erase(unique(reportedMap[id_list[i]].begin(), reportedMap[id_list[i]].end()), reportedMap[id_list[i]].end());
        if (reportedMap[id_list[i]].size() >= k)
        {

            for (int j = 0; j < reportedMap[id_list[i]].size(); ++j)
            {
                if (answer.find(reportedMap[id_list[i]][j]) == answer.end())
                    answer.insert(make_pair(reportedMap[id_list[i]][j], 1));
                else
                    answer[reportedMap[id_list[i]][j]]++;
            }
        }
    }

    for (int i = 0; i < id_list.size(); ++i)
    {
        ans[i] = answer[id_list[i]];
    }

    return ans;
}