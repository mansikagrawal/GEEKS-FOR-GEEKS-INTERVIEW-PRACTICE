/* link - https://atcoder.jp/contests/dp/tasks/dp_a */

#include <iostream>
#define inf 1e9
using namespace std;
int solve(int arr[], int n)
{
    int dp[n + 1]; // minimum cost to reach the ith stone
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        int option1 = abs(arr[i] - arr[i - 1]) + dp[i - 1];
        int option2 = (i == 2) ? inf : abs(arr[i] - arr[i - 2]) + dp[i - 2];
        dp[i] = min(option2, option1);
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    cout << solve(arr, n);
    return 0;
}iuuuuuu
