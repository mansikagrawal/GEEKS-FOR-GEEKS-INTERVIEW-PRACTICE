#include <bits/stdc++.h>
using namespace std;

int mincoins(int n, int coins[], int t, int dp[])
{
    // iterate over all states from 1...N
    for (int i = 1; i <= n; i++) {
        // initialse the current ans as max
        dp[i] = INT_MAX;
        for (int k = 0; k < t; k++) {
            if (i - coins[k] >= 0) {
                int subprob = dp[i - coins[k]];
                dp[i] = min(dp[i], subprob + 1);
            }
        }
    }
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
