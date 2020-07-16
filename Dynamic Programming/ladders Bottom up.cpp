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
int ladderbottomup(int n, int k, int dp[])
{
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                dp[i] += dp[i - j];
            }
        }
    }

    return dp[n];
}

int main()
{

    int n, k;
    cin >> n >> k;
    int dp[100] = { 0 };
    cout << ladderbottomup(n, k, dp);

    return 0;
}
