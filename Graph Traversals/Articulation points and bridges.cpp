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
int disc[N], low[N],tme;
vector<int> art_p;
vector<pair<int,int>> bridge;
void dfs(int cur,int par )
{
disc[cur]= low[cur] = tme++;
int no_child=0;
for(auto child:gr[cur])
{
if(disc[child]==0)
{

    dfs(child,cur);
    no_child++;

    low[cur] = min(low[cur], low[child]);
    if( par!=0 and low[child] >=disc[cur])
    {
        art_p.pb(cur);
    }

    //bridge
    if(low[child]>disc[cur]){
        bridge.pb({cur,child});
    }


}

else if(child !=par)
{
    //backedge
    low[cur] = min(low[cur],disc[child]);


}

}

//seperate case for root to be articulaton point
if(par==0 and no_child>=2)
{
    art_p.pb(cur);

}



return;



}

void solve(){
int i,j,k,n,m, ans=0, cnt=0,sum=0;
cin>>n>>m;
for(int i=0;i<m;i++)
{
    int x,y;
    cin>>x>>y;
    gr[x].pb(y);
    gr[y].pb(x);
}

tme=1;
dfs(1,0);
 for(auto x : art_p) cout<< x << " ";

}

int main()
{

    solve();
    return 0;
}





