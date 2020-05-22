#include <bits/stdc++.h>
using namespace std;

struct dsu
{
  vector<int> par, sz;
  int total_component;
  void init(int n)
  {
    par.resize(n);
    sz.resize(n);
    for (int i = 0; i < n; i++)
      par[i] = i;
    // initially 1's component is 1 2 is 2 three is 3
    for (int i = 0; i < n; i++)
      sz[i] = 1;
    total_component = n;
  }

  int get_superparent(int x)
  {
    if (x == par[x])
      return x;
    else
      par[x] = get_superparent(par[x]);
  }

  void unite(int x, int y)
  {
    int super_parent_x = get_superparent(x);
    int super_parent_y = get_superparent(y);
    // If they are in equal it means they are in the
    // same component and no need to be merged
    if (super_parent_x != super_parent_y) {
      par[super_parent_x] = super_parent_y;
      sz[super_parent_y] += sz[super_parent_x];
      sz[super_parent_x] = 0;
      total_component--;
    }
  }

} G;

void
solve()
{
  int i, j, k, l, m, n, ans = 0, cnt = 0, sum = 0;
  cin >> n >> m;
  G.init(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    G.unite(x, y);
  }

  // ALl elements are in their connected comp and
  // there is one super parent

  for (int i = 0; i < n; i++) {
    int super_parent_i = G.get_superparent(i);
    ans += n - G.sz[super_parent_i];
  }

  cout << (ans / 2);
}

int
main()
{
  solve();
  return 0;
}
