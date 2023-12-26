#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_map<string, int> mp;

    for (vector<string> cloth : clothes)
        mp[cloth[1]]++;

    for (auto it : mp)
    {
        answer *= (it.second + 1);
    }

    return answer - 1;
}