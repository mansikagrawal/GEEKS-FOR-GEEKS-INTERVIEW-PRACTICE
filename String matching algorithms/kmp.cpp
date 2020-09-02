#include<bits/stdc++.h>

# define MAX_N 100005
int  reset[MAX_N];
using namespace std;
 void resetArr(string str)
 {

     int i=0,j=-1;
reset[0]=-1;
     while(i<str.size())
     {


         while(j>=0 and str[i]!=str[j])
            j=reset[j];
     }

     i++;
     j++;
     reset[i]=j;

 }


  void KMP(string str,string pat)
  {
      resetArr(pat);



      int i=0,j=0;





   while(i<str.size()){

          while(j>=0 and str[i]!=pat[j])
            j=reset[j];


      i++;
      j++;
      if(j==pat.size())
      {

          cout<< "Found at index "<< i-j<<endl;
          j=reset[j];
      }

   }

  }


  int main()
  {

      string str,pat;
      cin>>str>>pat;
      KMP(str,pat);
      return 0;
  }
