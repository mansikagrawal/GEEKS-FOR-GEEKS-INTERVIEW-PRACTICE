/* Problem statement 

Given n wines in a row, 
with integers denoting the cost of each wine respectively.
Each year you can sale the first or the last wine in the row.
However, the price of wines increases over time. 
Let the initial profits from the wines be P1, P2, P3…Pn.
On the Yth year, the profit from the ith wine will be Y*Pi. 
 calculate the maximum profit from all the wines.  */

#include <bits/stdc++.h>
using namespace std;

int wines_prob(int wines[], int i, int j, int y, int dp[][100])
{
    // all bottle finish
    if (i > j)
        return 0;

    // not computing overlapping cases
    if (dp[i][j] != 0)
        return dp[i][j];

    // recursive case
    int op1 = wines[i] * y + wines_prob(wines, i + 1, j, y + 1, dp);
    int op2 = wines[j] * y + wines_prob(wines, i, j - 1, y + 1, dp);
    return dp[i][j] = max(op1, op2);
}

int main()
{
    int N = 5;
    int wines[] = { 2, 3, 5, 1, 4 };
    int dp[100][100] = { 0 };
    cout << wines_prob(wines, 0, N - 1, 1, dp);
    return 0;
}
