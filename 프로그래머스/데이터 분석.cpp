#include <string>
#include <vector>
#include <iostream>
using namespace std;


vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;

    // code date maximum remain
    int iExt = 0;
    if (ext == "code") iExt = 0;
    else if (ext == "date") iExt = 1;
    else if (ext == "maximum") iExt = 2;
    else if (ext == "remain") iExt = 3;

    for (int i = 0; i < data.size(); ++i)
    {
        if (data[i][iExt] < val_ext)
        {
            answer.push_back(data[i]);
        }
    }

    int isort_by = 0;
    if (sort_by == "code") isort_by = 0;
    else if (sort_by == "date") isort_by = 1;
    else if (sort_by == "maximum") isort_by = 2;
    else if (sort_by == "remain") isort_by = 3;


    for (int i = 0; i < answer.size(); ++i)
    {
        for (int j = 0; j < answer.size() - i - 1; ++j)
        {
            if (answer[j][isort_by] > answer[j + 1][isort_by])
            {
                vector<int> temp = answer[j];
                answer[j] = answer[j + 1];
                answer[j + 1] = temp;
            }
        }
    }

    return answer;
}