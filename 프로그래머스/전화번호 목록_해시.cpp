#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> mp;

    for (string it : phone_book)
    {
        mp.insert(make_pair(it, 1));
    }

    for (int i = 0; i < phone_book.size(); i++)
    {
        for (int j = 1; j < phone_book[i].size(); j++)
        {
            // substring
            string phone_number = phone_book[i].substr(0, j);
            if (mp[phone_number]) return false;
        }
    }


    return answer;
}