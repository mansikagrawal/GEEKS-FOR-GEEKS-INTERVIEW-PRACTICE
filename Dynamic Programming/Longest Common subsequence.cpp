
#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

int lcs(int, int, string, string);

int main()
{
    int t, n, k, x, y;

    cin >> t;
    while (t--) {
        cin >> x >> y; // Take size of both the strings as input
        string s1, s2;
        cin >> s1 >> s2; // Take both the string as input

        cout << lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// function to find longest common subsequence

int lcs(int x, int y, string s1, string s2)
{

    int dp[100][100];

    for (int i = 0; i <= x; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= y; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= x; i++) {
        int q = 0;
        for (int j = 1; j <= y; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                q = 1 + dp[i - 1][j - 1];
            }
            else {
                q = max(dp[i - 1][j], dp[i][j - 1]);
            }
            dp[i][j] = q;
        }
    }

    return dp[x][y];
}
