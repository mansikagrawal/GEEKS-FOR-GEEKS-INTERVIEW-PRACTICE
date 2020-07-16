/* Ladders problem 

Given N steps a user has to climb and atmost k steps can be 
taken 
EG: N=4 K=3
Output : 7
ways - 1,1,1,1
2,2
3,1
2,1,1
1,3
1,2,1
1,1,2
*/

#include <iostream>
using namespace std;
int ladderbottomupoptimised(int n, int k, int dp[])
{
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= k; i++) {
        dp[i] = 2 * dp[i - 1];
    }
    for (int i = k + 1; i <= n; i++) {
        dp[i] = 2 * dp[i - 1] - dp[i - k - 1];
    }

    return dp[n];
}

int main()
{

    int n, k;
    cin >> n >> k;
    int dp[100] = { 0 };
    cout << ladderbottomupoptimised(n, k, dp);

    return 0;
}
