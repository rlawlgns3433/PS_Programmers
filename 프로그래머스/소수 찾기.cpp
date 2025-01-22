#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

set<int> s;
vector<int> v;

bool isPrime(int number)
{
    if (number < 2)
        return false;

    for (int i = 2; i * i <= number; ++i)
    {
        if (number % i == 0)
            return false;
    }

    return true;
}

int solution(string number) {
    int answer = 0;
    sort(number.begin(), number.end());
    string val;

    do
    {
        val = "";
        for (int i = 0; i < number.size(); ++i)
        {
            val += number[i];
            int iVal = stoi(val);
            if (isPrime(iVal))
                s.insert(iVal);
        }
    } while (next_permutation(number.begin(), number.end()));

    return s.size();
}