//Initial template for C++


#include <bits/stdc++.h>
using namespace std;
int ExcelColumnNumber(string s);


 // } Driver Code Ends


//User function template for C++


int ExcelColumnNumber(string s)
{
    // This process is similar to
    // binary-to-decimal conversion
    int result = 0;
    for (const auto& c : s)
    {
        result *= 26;
        result += c  - 'A' + 1;
    }

    return result;
    // Your code goes here
}

// { Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<ExcelColumnNumber(s)<<endl;
    }
}  // } Driver Code Ends
