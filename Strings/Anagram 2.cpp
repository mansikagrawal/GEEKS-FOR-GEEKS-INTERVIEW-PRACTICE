#include<bits/stdc++.h>
using namespace std;
const int CHARS = 26;

// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2);

// Driver program to run the case
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str1,str2;
        cin>>str1>>str2;
        cout << remAnagram(str1, str2);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends


// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2)
{
    int charcnt1[26]={0}, charcnt2[26]={0};

int cnt=0;
    for(int i=0;i< str1.length();i++)
    charcnt1[str1[i]-'a']++;

    for(int i=0;i< str2.length();i++)
    {

        charcnt2[str2[i]-'a']++;

    }

    for(int i=0;i<26;i++)
    {

        cnt+=abs(charcnt1[i] - charcnt2[i]);
    }
    return cnt;


// Your code goes here
}
