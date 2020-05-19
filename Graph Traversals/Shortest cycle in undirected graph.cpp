#include<bits/stdc++.h>
using namespace std;
//#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back


const int N=10005, M=22;
vector<int> gr[N];

void bfs(int src,int n,int &ans )
{

vector<int> dist(n+1, INT_MAX);
queue<int> q;
q.push(src);
dist[src]=0;
while(!q.empty())
{

    int cur=q.front();
    q.pop();
    for(auto neig:gr[src])
    {

     if(dist[neig] == INT_MAX)
     {
         dist[neig] = dist[cur] +1;
         q.push(neig);

     }
     else if(dist[neig] >= dist[cur])
     {

         ans=min(ans,dist[neig] + dist[cur] +1);

     }


    }
}


}

void solve(){
int i,j,k,n,m;
cin>>n>>m;
for(int i=0;i<m;i++)
{
    int x,y;
    cin>>x>>y;
    gr[x].pb(y);
    gr[y].pb(x);
}


int ans=n+1;
for(int i=1 ; i <=n ;i++)
    bfs(i,n,ans);
if(ans==n+1)
    cout<< " No cycle ";
else
    cout<< " Shortest cycle is " << ans;

}

int main()
{

    solve();
    return 0;
}






