/* Grid based dp
This section can contain two type of problems
1) Given a matrix with each block some cost find a path to reach
one end to another end with min cost.
2) Find the number of ways to reach one end to another end. */
#include <bits/stdc++.h>
using namespace std;

#define R 3
#define C 3
int dp[3][3];
int cost[R][C] = { { 1, 2, 3 },
    { 4, 8, 2 },
    { 1, 5, 3 } };
int grid_dp()

{
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {

            // base case
            if (i == 0 and j == 0) {
                dp[i][j] = cost[0][0];
            }
            else if (j == 0) {

                dp[i][j] = dp[i - 1][0] + cost[i][0];
            }
            else if (i == 0) {

                dp[i][j] = dp[0][j - 1] + cost[0][j];
            }
            else {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + cost[i][j];
            }
        }
    }
}

int main()
{

    grid_dp();
    for (int i = 0; i < R; i++) {
        cout << endl;
        for (int j = 0; j < C; j++) {
            cout << dp[i][j] << " ";
        }
    }
    return 0;
}
