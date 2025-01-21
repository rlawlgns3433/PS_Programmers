#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;

    int lWallet = 0;
    int sWallet = 0;

    int lBill = 0;
    int sBill = 0;

    if (wallet[0] < wallet[1])
    {
        lWallet = wallet[1];
        sWallet = wallet[0];
    }
    else
    {
        lWallet = wallet[0];
        sWallet = wallet[1];
    }

    if (bill[0] < bill[1])
    {
        lBill = bill[1];
        sBill = bill[0];
    }
    else
    {
        lBill = bill[0];
        sBill = bill[1];
    }

    int temp = 0;

    while (true)
    {
        if (lWallet >= lBill && sWallet >= sBill)
            return answer;

        lBill /= 2;
        if (lBill < sBill)
        {
            temp = lBill;
            lBill = sBill;
            sBill = temp;
        }

        answer++;
    }
}