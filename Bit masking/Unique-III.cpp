#include<iostream>
using namespace std;
int main()
{int ans=0;
    int n;
    int cnt[64]={0};
    cin>>n;
    for(int i=0;i<n;i++)
    {

        int no;
        cin>>no;
        int j=0;
        while(no>0)
        {
            int last_bit=(no&1);
            cnt[j]+=last_bit;
            j++;
            no=no>>1;

        }}

        int p=1;
        for(int i=0;i<64;i++){
            cnt[i]%=3;
            ans+=cnt[i]*p;
            p=p<<1;
            }


     cout<<ans<<endl;
}
