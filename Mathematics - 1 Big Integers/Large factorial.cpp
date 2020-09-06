#include <bits/stdc++.h>
using namespace std;

void multiply(int* a, int& n, int no)
{
    int carry = 0;
    for (int i = 0; i < n; i++) {
        int product = a[i] * no + carry;
        a[i] = product % 10;
        carry = product / 10;
    }
    while (carry) {
        a[n] = carry % 10;
        carry /= 10;
        n++;
    }
}

void bigfactorial(int number)
{
    int* a = new int[1000];
    memset(a, sizeof(a), 0);
    a[0] = 1;
    int n = 1;
    for (int i = 2; i <= number; i++) {
        multiply(a, n, i);
    }
    // printf the factorial
    for (int i = n - 1; i >= 0; i--)
        cout << a[i];
}

int main()
{
    int n;
    cin >> n;
    bigfactorial(n);
    return 0;
}
