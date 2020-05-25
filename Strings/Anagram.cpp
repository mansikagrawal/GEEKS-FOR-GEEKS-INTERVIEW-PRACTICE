#include<bits/stdc++.h>
using namespace std;
bool anagram(string s1,string s2){

    if(s1.length()!=s2.length()){
        return false;
    }
    int n=s1.length();
    unordered_map<char,int> freq;
    for(int i=0;i<n;i++){
        freq[s1[i]]++;
        freq[s2[i]]--;
    }
    for(auto count:freq){
        if(count.second){
            return false;
        }
    }
    return true;
}
int main(){

    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        if(anagram(s1,s2)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
