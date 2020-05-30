#include <iostream>
using namespace std;

#define li 10000
void prime_sieve(int* p)
{
    for (int i = 3; i <= li; i += 2)
        p[i] = 1;

    for (long long i = 3; i <= li; i += 2) {
        if (p[i] == 1) {
            for (int j = i * i; j <= li; j += i) {
                p[j] = 0;
            }
        }
    }
    p[2] = 1;
    p[0] = p[1] = 0;
}

int main()
{
    int n;
    cin >> n;

    int p[1000005] = { 0 };

    prime_sieve(p);
    for (int i = 0; i <= n; i++) {
        if (p[i])
            cout << i << " ";
    }

    return 0;
}
