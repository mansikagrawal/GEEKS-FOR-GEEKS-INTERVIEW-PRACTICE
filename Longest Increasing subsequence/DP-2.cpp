#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = { 1, 5, 2, 3, 4, 9, 6, 10 };
    int n = 8;
    int dp[n + 1];
    dp[0] = INT_MIN;
    for (int i = 1; i <= n; i++) {
        dp[i] = INT_MAX;
    }
    for (int i = 0; i < n; i++) {
        for (int length = 0; length < n; length++) {
            if (dp[length] < a[i] and a[i] < dp[length + 1]) {
                dp[length + 1] = a[i];
            }
        }
    }
    int lis = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i] != INT_MAX)
            lis = i;
    }

    cout << lis;

    return 0;
}
