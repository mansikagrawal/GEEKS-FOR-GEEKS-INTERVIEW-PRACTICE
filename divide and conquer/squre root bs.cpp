#include<iostream>
using namespace std;


  float bssqrt(int n,int p)
  {

      int s=0,e=n;
      float ans;
      int mid;


      while(s<=e)
      {

          int mid=(s+e)/2;
          if(mid*mid==n)
          {

              ans=mid;
              break;
          }
          if(mid*mid<n)
          {

           s=mid+1;
              ans=mid;

          }
          else
          {
 e=mid-1;

          }

          float inc=0.1;

          for(int i=0;i<p;i++)
          {

              while(ans*ans<=n)
              {
                  ans+=inc;

              }
              ans-=inc;
              inc/=10;



          }
          return ans;

      }
  }

  int main()
  {

      int n,p;
      int t;
      cin>>t;
      while(t-->0)
      {


      cout<<"Enter n ";
      cin>>n;
      cout<<"Enter p ";
      cin>>p;
      cout<<bssqrt(n,p);}

      return 0;
  }
