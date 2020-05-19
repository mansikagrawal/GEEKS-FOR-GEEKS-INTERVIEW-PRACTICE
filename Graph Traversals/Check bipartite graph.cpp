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
int vis[N];
bool ans=0;
int col=1;
void dfs(int cur,int par,int col )
{
vis[cur]=col;
for(auto child:gr[cur])
{
if(vis[child]==0)
{

    dfs(child,cur,3-col);

}

else if(child !=par and col==vis[child])
{
    //backedge
    ans=1;

}

}



return;



}

void solve(){
int i,j,k,n,m,;
cin>>n>>m;
for(int i=0;i<m;i++)
{
    int x,y;
    cin>>x>>y;
    gr[x].pb(y);
    gr[y].pb(x);
}


dfs(1,0,1);
if(ans==1)
    cout<< "Not bipartite";
else
    cout<< "Bipartite";


}

int main()
{

    solve();
    return 0;
}






