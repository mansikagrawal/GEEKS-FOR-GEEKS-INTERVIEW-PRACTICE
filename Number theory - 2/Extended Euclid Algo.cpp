#include <bits/stdc++.h>
using namespace std;

int x, y, gcd;
void ext_euc(int a, int b)
{
    // Base case
    if (b == 0) {
        x = 1;
        y = 0;
        gcd = a;
        return;
    }
    ext_euc(b, a % b);
    int cx = y;
    int cy = x - (a / b) * y;
    x = cx;
    y = cy;
}

int main()
{
    ext_euc(18, 30);
    cout << x << "," << y;

    return 0;
}
