#include <iostream>
using namespace std;

int fib(int n)
{
    int dp[100] = { 0 };
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main()
{
    int n = 5;

    cout << fib(n);
    return 0;
}
