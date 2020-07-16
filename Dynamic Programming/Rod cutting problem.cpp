
#include <iostream>
using namespace std;

// recursion method
int maxProfit(int arr[], int totalLen)
{
    int best = 0;
    if (totalLen == 0)
        return 0;

    for (int len = 1; len <= totalLen; ++len) {
        int netprofit = arr[len] + maxProfit(arr, totalLen - len);
        best = max(best, netprofit);
    }

    return best;
}
// bottom up dp
int maxprofitbottomup(int arr[], int totalLen)
{
    int dp[100] = { 0 };
    for (int len = 1; len <= totalLen; len++) {
        int best = 0;
        for (int cut = 1; cut <= len; cut++) {
            best = max(best, arr[cut] + dp[len - cut]);
        }
        dp[len] = best;
    }
    return dp[totalLen];
}

int main()
{

    int priceOfEachLen[100];
    int totalLen;
    cin >> totalLen;

    for (int i = 1; i <= totalLen; i++)
        cin >> priceOfEachLen[i];

    int ans = maxProfit(priceOfEachLen, totalLen);
    cout << ans;

    cout << endl
         << maxprofitbottomup(priceOfEachLen, totalLen);

    return 0;
}
