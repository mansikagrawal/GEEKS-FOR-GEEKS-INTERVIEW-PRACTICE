#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to count the number of substrings
*   starting and ending with 1
*   n: size of string
*   a: input string
*/
long binarySubstring(int n, string a){

    long res=0;
    for(int i=0;i<a.length();i++)
    {
        if(a[i] =='1')
        res++;
    }
    return (res*(res-1))/2;
    // Your code here

}


// { Driver Code Starts.

int main()
{
    int t,n,count;
    string a;
    cin>>t;
    while(t--)
    {
        count = 0;
        cin >> n;
        cin >> a;

        cout << binarySubstring(n, a) << endl;
    }
}
  // } Driver Code Ends
