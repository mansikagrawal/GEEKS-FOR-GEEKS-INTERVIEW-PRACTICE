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
  int i, j, k, l, m, n, ans = 0, cnt = 0, sum = 0;
  cin >> n >> m;
  G.init(n);
  bool cycle = 0;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;  // MAke all edges as 0 based index
    if (G.get(x) != G.get(y)) {
      // different component
      G.unite(x, y);

    } else {
      // same component ie, path from x to y
      cycle = 1;
      // cout<< " This edge will give me a cycle ";
    }
  }

  if (cycle)
    cout << " cycle in graph ";
  else
    cout << "No cycle ";
}

int main() {
  solve();
  return 0;
}
