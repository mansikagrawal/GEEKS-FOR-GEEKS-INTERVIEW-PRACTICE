#include <bits/stdc++.h>

using namespace std;

vector<int> primeSieve(int* p, int n)
{

    p[0] = p[1] = 0;
    p[2] = 1;

    for (int i = 3; i <= n; i += 2) {

        p[i] = 1;
    }

    for (int i = 3; i <= n; i += 2) {
        if (p[i]) {

            for (int j = i * i; j <= n; j += 2 * i) {
                p[j] = 0;
            }
        }
    }
    vector<int> primes;
    primes.push_back(2);

    for (int i = 3; i <= n; i++) {

        if (p[i] == 1) {

            primes.push_back(i);
        }
    }

    return primes;
}

int no_of_divisors(int m, vector<int>& primes)
{

    int i = 0;
    int p = primes[0];
    int ans = 1;
    while (p * p <= m) {

        if (m % p == 0) {
            int count = 0;

            while (m % p == 0) {
                count++;
                m = m / p;
            }

            ans = ans * (count + 1);
        }
        i++;
        p = primes[i];
    }

    if (m != 1) {

        ans = ans * 2;
    }

    return ans;
}
int main()
{

    int N = 1000000;
    int p[N];
    for (int i = 0; i < N; i++)
        p[i] = 0;
    vector<int> primes = primeSieve(p, 10000);
    int t;
    cin >> t;
    while (t--) {

        int no;
        cin >> no;
        int divisors = no_of_divisors(no, primes);
        cout << divisors << " ";
    }
    return 0;
}
