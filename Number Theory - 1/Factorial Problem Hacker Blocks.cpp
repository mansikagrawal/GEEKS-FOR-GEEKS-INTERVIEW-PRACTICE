
#include <bits/stdc++.h>
using namespace std;

#define MAX 100000000

int main()
{

    int t;
    cin >> t;
    while (t--) {

        int n, k;
        cin >> n >> k;
        int ans = MAX;

        int occ = 0;
        // factors of k along with their powers
        for (int i = 2; i * i <= k; i++) {
            if (k % i == 0) {
                occ = 0;
                while (k % i == 0) {

                    occ++;
                    k = k / i;
                }

                // find out powers of i in n! ie, n!= n/p +
                //n/p^2.......
                int cnt = 0;
                long long p = i;
                while (p <= n) {

                    cnt += n / p;
                    p = p * i;
                }

                ans = min(ans, cnt / occ);
            }
        }

        // we may have a case when a prime factor is left
        // ex case n=10

        if (k > 1) {

            int p = k;
            int cnt = 0;
            while (p <= n) {

                cnt += n / p;
                p *= k;
            }
            ans = min(ans, cnt);
        }

        if (ans == MAX) {
            ans = 0;
        }
        cout << ans << endl;
    }
    return 0;
}
