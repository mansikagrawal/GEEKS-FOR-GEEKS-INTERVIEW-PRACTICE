#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 3005;
int sieve(int n)
{

    int pr[n+1]={0};

    vector<int> primes;

    int i,j;

    for(i=2;i<=n;i++)
    {

        if(!pr[i])
        {

            primes.push_back(i);
            for(j=i;j<=n;j+=i)
            {
                pr[j]++;
            }
        }
    }

    int ans=0;
    for(int i=2;i<=n;i++)
    {

        if(pr[i] == 2)
            ans++;
    }


    return ans;


    }


    void solve()
    {

        int i,j,k,n,m,ans=0,cnt=0,sum=0;
        cin>>n;
        cout<< sieve(n);
        return;
    }


    int32_t main()
    {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        solve();
        return 0;

    }
