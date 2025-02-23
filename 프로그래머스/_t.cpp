#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int answer = 1e9;
int fat[3][3] = { {1,1,1},{5,1,1},{25,5,1} };
map<string, int> stringToInt;

void dfs(vector<int> picks, vector<string> minerals, int pos, int sum)
{
	if (pos == minerals.size() || (picks[0] == 0 && picks[1] == 0 && picks[2] == 0))
	{
		answer = min(sum, answer);
		return;
	}

	for (int i = 0; i < 3; ++i)
	{
		if (picks[i] == 0)
			continue;

		picks[i]--;

		int tempPos = min(pos + 5, (int)minerals.size());
		int tempSum = sum;

		for (int j = pos; j < tempPos; ++j)
		{
			tempSum += fat[i][stringToInt[minerals[j]]];
		}

		dfs(picks, minerals, tempPos, tempSum);

		picks[i]++;
	}
}

int solution(vector<int> picks, vector<string> minerals) {

	stringToInt.insert({ "diamond", 0});
	stringToInt.insert({ "iron", 1});
	stringToInt.insert({ "stone", 2});

	dfs(picks, minerals, 0, 0);

	return answer;
}

int main()
{
	cout << solution({ 0,1,1 },{ "diamond", "diamond", "diamond", "diamond", "diamond", "iron", "iron", "iron", "iron", "iron", "diamond" });
}