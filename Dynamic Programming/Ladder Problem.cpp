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
TC-O(k)
*/

#include <iostream>
using namespace std;
int laddertopdown(int n, int k, int dp[])
{
    //base case
    if (n == 0)
        return 1;
    // look up
    if (dp[n] != 0)
        return dp[n];
    //rec case
    int ways = 0;
    for (int i = 1; i <= k; i++) {
        if (n - i >= 0)
            ways += laddertopdown(n - i, k, dp);
    }
    return dp[n] = ways;
}

int main()
{

    int n, k;
    cin >> n >> k;
    int dp[100] = { 0 };
    cout << laddertopdown(n, k, dp);

    return 0;
}
