#include<bits/stdc++.h>

using namespace std;
//#define int long long int

#define ld long double
# define F first
# define S second
# define P pair < int, int >
#define pb push_back

const int N = 10005,
    M = 22;
vector < int > gr[N], grr[N];
int vis[N], comp[N];
vector < int > order;

void dfs_reverse(int cur, int col) {
    comp[cur] = col;
    vis[cur] = 1;
    for (auto x: grr[cur]) {
        if (!vis[x]) {
            dfs_reverse(x, col);

        }
    }

}

void dfs(int cur) {
    vis[cur] = 1;
    for (auto x: gr[cur]) {
        if (!vis[x]) {
            dfs(x);

        }
    }

    order.pb(cur);
}

void solve() {
    int i, j, k, n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        gr[x].pb(y);
        grr[y].pb(x);
    }

    for (int i = 1; i <= n; i++) {

        if (!vis[i])
            dfs(i);

    }
    memset(vis, 0, sizeof(vis));
    int col = 1;

    for (int i = n; i >= 0; i--) {
        if (!vis[order[i]]) {
            dfs_reverse(order[i], col);
            col++;
        }

    }

    for (int i = 1; i <= n; i++)
        cout << i << "-->" << comp[i] << "\n";

}

int main() {

    solve();
    return 0;
}
