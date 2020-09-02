#include<bits/stdc++.h>
using namespace std;
void naive(string s,string pat)
{

    for(int i=0;i<=s.size()-pat.size();i++)
    {int j;
        for(j=0;j<pat.size();j++)
        {

            if(s[i+j]!=s[j])
            {

                break;
            }
        }
            if(j==pat.size())
                cout<<i<<endl;

    }

}
int main()
{

string s,pat;
cin>>s>>pat;
naive(s,pat);
return 0;
}
