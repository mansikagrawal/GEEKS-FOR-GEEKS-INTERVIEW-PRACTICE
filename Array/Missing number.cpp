
// The idea is that sum of n natural numbers is n*(n+1)/2 and sum up the  elements
// taken input . Substract those and you'll get the missing number.
#include <iostream>
using namespace std;

int main() {

    int t;
    cin>>t;
    int res;
    while(t--)
    {
        int n,i;
        cin>>n;
        int s=0;
        int res=0;
        int x;

        for( i=1;i<n;i++)
        {
           cin>>x;
           s+=x;


        }

        cout<<(n*(n+1)/2)-s<<"\n";





    }
	//code
	return 0;
}
