#include<iostream>
using namespace std;
typedef long long int ll;
int main()
{

    ll n;
    cin>>n;
    ll a[n];ll temp=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        temp^=a[i];
        }
       // cout<<"temp"<<temp<<endl;
        ll elem=temp;
        ll pos=0;
       // cout<<"elem"<<elem<<endl;
        while((elem&1)!=1)
        {

            elem=(elem>>1);
            pos++;

        }
        //cout<<"pos is "<<pos<<endl;
        ll mask=(1<<pos);
       // cout<<"mask"<<mask<<endl;
        ll x=0,y=0;
        for(ll i=0;i<n;i++){
            if((a[i]&mask)>0)
                x=x^a[i];
        }
       // cout<<" x" << x<<endl;
        y=temp^x;
        cout<<min(x,y)<<" " <<max(x,y)<<endl;

}
