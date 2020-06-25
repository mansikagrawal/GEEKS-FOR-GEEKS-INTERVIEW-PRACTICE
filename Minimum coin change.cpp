#include <bits/stdc++.h>
using namespace std;

int mincoins(int n, int coins[], int t, int dp[])
{
    // no coins
    if (n == 0)
        return 0;
    // look up case
    if (dp[n] != 0)
        return dp[n];
    int ans = INT_MAX;
    for (int i = 0; i < t; i++) {
        if (n - coins[i] >= 0) {
            int subprob = mincoins(n - coins[i], coins, t, dp);
            ans = min(ans, subprob + 1);
        }
    }
    dp[n] = ans;
    return dp[n];
}

int main()
{
    int N = 15;
    int coins[] = { 1, 7, 10 };
    int dp[100] = { 0 };
    cout << mincoins(N, coins, 3, dp);
    return 0;
}
