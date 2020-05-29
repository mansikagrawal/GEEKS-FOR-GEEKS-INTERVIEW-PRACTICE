//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

int VersionCompare(string v1, string v2) ;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string v1, v2;
        cin>>v1;
        cin>>v2;
        cout<<VersionCompare(v1,v2)<<endl;
    }
    return 0;
}


 // } Driver Code Ends


//User function Template for C++

int VersionCompare(string v1, string v2)
{
    int i=0, j=0;
    int vnum1=0, vnum2=0;
    for(; (i<v1.length() or j < v2.length());)
    {


        while(i< v1.length() and v1[i] != '.')
        {
            vnum1=vnum1*10 + v1[i]-'0';
            i++;
        }
         while(j< v2.length() and v2[j] != '.')
        {
            vnum2=vnum2*10 + v2[j]-'0';
            j++;
        }

        if(vnum1>vnum2)
        return 1;
        if(vnum1<vnum2)
        return -1;

        vnum1=vnum2=0;
        i++;
        j++;



    }

    return 0;

}

// { Driver Code Starts.


  // } Driver Code Ends
