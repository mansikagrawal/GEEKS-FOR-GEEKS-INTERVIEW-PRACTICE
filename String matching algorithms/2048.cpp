#include<bits/stdc++.h>
using namespace std;
char spell[][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

 void print(int n)
 {
     if(n==0)
        return;
cout<<spell[n%10]<<" ";
     print(n/10);
    // cout<<spell[n%10]<<" ";

 }

int main()
{
int n;
cout<<"Enter n";
cin>>n;
print(n);

return 0;

}
