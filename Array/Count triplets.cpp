#include <bits/stdc++.h>
using namespace std;

int triplet( int arr[], int n)
{
    sort(arr,arr+n);

    int count=0;
    for(int i=0;i<n;i++)
    {
        int l=0;int h=n-1;
        while(l<h){
        if( l!=i and h!=i and (arr[i] == arr[l] + arr[h]))
        count++;
        if(arr[l] +arr[h] > arr[i])
        h--;
        else
        l++;
        }

    }

    return count>0 ? count : -1;




}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int arr[n];
        for(int i=0;i<n;i++)
        cin >> arr[i];


        cout<<triplet(arr,n)<<endl;

       // delete arr;

    }
	//code
	return 0;
}
