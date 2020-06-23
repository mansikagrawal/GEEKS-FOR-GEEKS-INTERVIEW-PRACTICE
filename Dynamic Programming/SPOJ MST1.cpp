/* Link to the problem
      https://www.spoj.com/problems/MST1/ */
      
#include <bits/stdc++.h>
using namespace std;
# define ll long long 
#define N 20000001
ll dp[N];
void mintoone(ll n)
{
    dp[1]=0;
    for(ll i=2;i<=n;i++)
    {
        ll op1, op2, op3;
        op1=op2=op3=INT_MAX;
        if(i%3==0)             
        op1 = dp[i/3];
        if(i % 2==0)
        op2=dp[i/2];
        
        op3=dp[i-1];
        dp[i] = min(min(op1,op2), op3) + 1;
        
    }
}
 
int main() {
    ll t;
    cin>> t;
    mintoone(N-1);          // precompute outside testcases loop to avoid tle 
    for(ll k=1;k<=t;k++)
    {
        ll x;
        cin>> x;
        cout<< "Case " << k << ": " <<dp[x]<<endl;
        
    }
    return 0;
} 
