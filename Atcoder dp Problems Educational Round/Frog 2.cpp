/* link - https://atcoder.jp/contests/dp/tasks/dp_b */

#include <iostream>
#define inf 1e9
using namespace std;
int solve(int arr[], int n, int k)
{
    int dp[n + 1]; // minimum cost to reach the ith stone
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = inf;
        
        // iterating all the k states behind i to reach the i in min cost
        for (int j = i - 1; j >= 1 and (i - j) <= k; j--) {
            dp[i] = min(dp[i], abs(arr[i] - arr[j]) + dp[j]);
        }
    }

    return dp[n];
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    cout << solve(arr, n, k);
    return 0;
}
