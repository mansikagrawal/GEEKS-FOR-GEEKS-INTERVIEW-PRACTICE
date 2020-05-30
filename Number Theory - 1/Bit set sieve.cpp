#include <bits/stdc++.h>

using namespace std;

bitset<10000005> b;
const int n = 10000000;
vector<int> primes;

void sieve()
{

    b.set();
    b[0] = b[1] = 0;
    for (long long int i = 2; i <= n; i++) {
        if (b[i]) {
            primes.push_back(i);
            for (long long int j = i * i; j <= n; j += i) {
                b[j] = 0;
            }
        }
    }
}

int main()
{

    sieve();
    for (int i = 0; i <= 100; i++)
        cout << primes[i] << " ";
    return 0;
}
