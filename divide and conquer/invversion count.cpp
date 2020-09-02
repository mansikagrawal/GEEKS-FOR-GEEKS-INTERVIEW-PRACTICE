#include<iostream>
using namespace std;

int mergefn(int arr[],int temp[],int left,int mid,int right)
{



    int i=left;
    int j=mid;
    int k=left;
    int inv_cnt=0;



    while((i<=mid-1 ) && (j<=right))
    {

        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else
        {

            temp[k++]=arr[j++];
            inv_cnt+=(mid-i);
        }



    }


    while(i<=mid-1)
        temp[k++]=arr[i++];
    while(j<=right)
        temp[k++]=arr[j++];



    for(i=left;i<=right;i++)
        arr[i]=temp[i];

    return inv_cnt;


}


int mergesort(int arr[],int temp[],int left,int right)
{

 int inv_cnt=0;

    if(right>left)
    {

        int mid=(left+right)/2;


        inv_cnt+=mergesort(arr,temp,left,mid);
        inv_cnt+=mergesort(arr,temp,mid+1,right);
        inv_cnt+=mergefn(arr,temp,left,mid+1,right);

    }
    return inv_cnt;
}




int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int temp[n];
    cout<<mergesort(arr,temp,0,n-1);

}
