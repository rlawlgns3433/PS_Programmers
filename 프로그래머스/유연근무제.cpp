#include <string>
#include <vector>
using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    int size = schedules.size();

    for (int i = 0; i < size; ++i)
    {
        bool pass = true;
        int day = startday;
        for (int j = 0; j < 7; ++j)
        {
            if (day == 6 || day == 7)
            {
                day++;
                if (day > 7)
                    day = 1;
                continue;
            }

            int hour = schedules[i] / 100;
            int minute = schedules[i] % 100;
            int time = hour * 60 + minute;

            int logHour = timelogs[i][j] / 100;
            int logMinute = timelogs[i][j] % 100;
            int logTime = logHour * 60 + logMinute;

            if (time + 10 < logTime)
            {
                pass = false;
                break;
            }

            day++;
        }

        if (pass)
            answer++;
    }

    return answer;
}