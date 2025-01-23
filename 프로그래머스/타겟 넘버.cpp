#include <string>
#include <vector>
using namespace std;

int answer = 0;
void dfs(const vector<int>& numbers, int cur, int target, int n)
{
	if (cur == target && n == numbers.size() - 1)
	{
		answer++;
		return;
	}

	if (n + 1 >= numbers.size())
		return;

	dfs(numbers, cur + numbers[n + 1], target, n + 1);
	dfs(numbers, cur - numbers[n + 1], target, n + 1);
}

int solution(vector<int> numbers, int target) {

	dfs(numbers, numbers[0], target, 0);
	dfs(numbers, -numbers[0], target, 0);

	return answer;
}