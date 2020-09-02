#include<iostream>

using namespace std;


int findfunc(int arr[],int n,int s,int e,int key)
{
    if(s>e)
        return -1;

    int mid=(s+e)/2;

    if(arr[mid]==key)
        return mid;


    if(arr[s]<=arr[mid])
    {

        if(key>=arr[s] && key <=arr[mid] )
                return findfunc(arr,n,s,mid-1,key);
        else
            return findfunc(arr,n,mid+1,e,key);


    }



    if(key>=arr[mid] && key<=arr[e])

        return findfunc(arr,n,mid+1,e,key);

    return findfunc(arr,n,s,mid-1,key);




}



int main()
{

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter key ";
    int key;
    cin>>key;
    cout<<"Output is "<< findfunc(a,n,0,n-1,key);
    return 0;
}
