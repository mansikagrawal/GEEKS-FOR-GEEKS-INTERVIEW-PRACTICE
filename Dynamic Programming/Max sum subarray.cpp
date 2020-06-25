/* Max sum subarray */

#include <bits/stdc++.h>
using namespace std;

int maxsum(int a[], int n)
{
    int dp[100] = { 0 };
    dp[0] = a[0] > 0 ? a[0] : 0;
    int maxsofar = dp[0];
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + a[i];
        if (dp[i] < 0)
            dp[i] = 0;
        maxsofar = max(dp[i], maxsofar);
    }
    return maxsofar;
}
int main()
{
    int arr[] = { -3, 2, 5, -1, 6, 3, -2, 7, -5, 2 };
    int n = sizeof(arr) / sizeof(int);
    cout << maxsum(arr, n);
    return 0;
}
