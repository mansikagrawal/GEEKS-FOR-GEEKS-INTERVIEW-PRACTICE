// lower bound and upper bound using binary search

#include<iostream>
using namespace std;


int lb(int a[],int n, int key)
{

    int s=0;
    int e=n-1;
    int mid,ans=-1;


    while(s<=e)
    {

        mid=(s+e)/2;

        if(a[mid]==key)
        {

            ans=mid;
            e=mid-1;
        }
        else if(a[mid]>key)
        {

            e=mid-1;
        }
        else
        {

            s=mid+1;
        }


    }
    return ans;
}


int ub(int a[],int n,int key)
{
    int s=0;
    int e=n-1;
    int mid,ans=-1;


    while(s<=e)
    {

        mid=(s+e)/2;

        if(a[mid]==key)
        {

            ans=mid;
            s=mid+1;
        }
        else if(a[mid]>key)
        {

            e=mid-1;
        }
        else
        {

            s=mid+1;
        }


    }
    return ans;

}
int main()
{

   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)
    cin>>arr[i];
   int key;
   cin>>key;
    cout<<lb(arr,n,key)<<endl;
    cout<<ub(arr,n,key)<<endl;
    return 0;


}
