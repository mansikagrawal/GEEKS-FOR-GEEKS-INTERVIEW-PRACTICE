#include<iostream>
using namespace std;


int main()
{

    int a[]={5,6,7,1,2,3,4};
    int n=sizeof(a)/sizeof(int);

    int s=0;
    int e=n-1;
    while(s<=e)
    {
        int mid=(s+e)/2;

        if(a[mid]>a[mid+1])
        {

            cout<<mid<<endl;
            break;
        }
        if(a[mid]<a[mid-1])
        {

            cout<<mid-1;
            break;
        }

        if(a[s]>=a[mid])
        {

            e=mid-1;
        }
        else
        {

            s=mid+1;
        }


    }
    if(s>e)
    cout<<"Not found ";
    return 0;


}
