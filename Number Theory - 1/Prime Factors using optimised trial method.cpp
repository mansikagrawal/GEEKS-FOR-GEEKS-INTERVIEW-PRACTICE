#include <bits/stdc++.h>
using namespace std;

void printfactors(int n)
{
    vector<pair<int, int> > factors;
    int cnt = 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            factors.push_back(make_pair(i, cnt));
        }
    }

    if (n != 1) {
        // whatever is left is prime
        factors.push_back(make_pair(n, 1));
    }

    for (auto p : factors) {

        cout << p.first << "^" << p.second << endl;
    }

    return;
}

int main()
{

    int n;
    cin >> n;
    printfactors(n);

    return 0;
}
