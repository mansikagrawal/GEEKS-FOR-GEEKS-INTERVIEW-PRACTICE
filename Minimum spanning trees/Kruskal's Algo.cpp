#include <bits/stdc++.h>
using namespace std;

struct dsu {
  vector<int> p;

  void init(int NN) {
    p.clear();
    p.resize(NN);

    iota(p.begin(), p.end(), 0);
  }

  int get(int x) {
    if (x == p[x])
      return x;
    else
      p[x] = get(p[x]);
  }

  void unite(int x, int y) {
    int x1 = get(x);
    int y1 = get(y);

    if (x1 != y1) {
      p[x1] = y1;
    }
  }

} G;

void solve() {
  int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
  cin >> n >> m;

  vector<vector<int>> edges(m);
  for (int i = 0; i < m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    x--, y--;
    edges[i] = {w, x, y};
    // written as w as to sort according to their weights
  }
  sort(edges.begin(), edges.end());
  dsu G;
  G.init(n);
  for (int i = 0; i < m; i++) {
    int x = edges[i][1];
    int y = edges[i][2];
    int w = edges[i][0];
    // cout << w << " " << x << " " << y << endl;

    if (G.get(x) != G.get(y)) {
      // can take this edge
      G.unite(x, y);
      // include all edges which does not result in cycle
      ans += w;
    }
  }
  cout << ans;
}
int main() {
  solve();
  return 0;
}
