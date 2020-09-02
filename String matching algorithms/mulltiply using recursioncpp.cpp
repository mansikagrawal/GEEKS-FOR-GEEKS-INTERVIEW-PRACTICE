#include<bits/stdc++.h>
using namespace std;
 int mul(int x,int y)
 {

     if(y==0)
        return 0;


     if(y>0)
        return x+mul(x,y-1);
     if(y<0)
        return -mul(x,-y);

 }

int main()
{

int x;int y;
cin>>x>>y;
cout<<mul(x,y);
return 0;
}
