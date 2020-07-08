#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = { 1, 5, 2, 3, 4, 9, 6, 10 };
    int n = 8;
    int dp[n];
    for (int i = 0; i < n; i++) {
        // every element can end at length 1
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i]);
    cout << ans;

    return 0;
}
