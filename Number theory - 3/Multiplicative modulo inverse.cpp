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
// Assuming that the modulo exists
int getmoduloinverse(int a, int m)
{

    ext_euc(a, m);
    // To make the answer positive we have to make modulo
    return (x + m) % m;
}

int main()
{

    cout << getmoduloinverse(6, 7);

    return 0;
}
