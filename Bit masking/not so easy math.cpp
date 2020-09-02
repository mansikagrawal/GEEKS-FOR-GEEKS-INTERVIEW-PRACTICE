#include<iostream>
using namespace std;
typedef long long int ll;
int main() {
ll ans=0;
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		int primes[]={2,3,5,7,11,13,17,19};

ll subset=(1<<8)-1;
for(ll i=1;i<=subset;i++ )
{

ll denom=1;

ll setbit=__builtin_popcount(i);
for(ll j=0;j<=7;j++)
{

if(i & (1<<j))
{
	denom*=primes[j];
}


}
if(setbit&1)
{


	ans+=n/denom;
}
else{
	ans-=n/denom;
}
}
cout<<ans<<endl;
ans=0;



	}
	return 0;
}
