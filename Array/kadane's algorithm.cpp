#include <iostream>
using namespace std;

// The idea is to calculate the max upto the current element and compare the current element on the basis of the greater element
int subarray(int a[], int n)
{
    int max0=a[0],maxi=a[0];
    for(int i=1;i<n;i++)
    {
        maxi=max(a[i], maxi+a[i]);
        if(max0<maxi)
        max0=maxi;
    }
    return max0;
}


int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        cout<<subarray(a,n)<<endl;
    }
	//code
	return 0;
}
