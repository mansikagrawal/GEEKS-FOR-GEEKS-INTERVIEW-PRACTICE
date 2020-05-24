#include <bits/stdc++.h>
using namespace std;

class Graph {
 public:
  int v;
  list<pair<int, int>> *adj;

  Graph(int v) {
    this->v = v;
    adj = new list<pair<int, int>>[v];
  }

  void addEdge(int u, int v ,int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }

  int findminvertex(int *weight, bool *visited, int v) {
    int minvertex = -1;
    for (int i = 0; i < v; i++) {
      if (!visited[i] and (minvertex == -1 or weight[i] < weight[minvertex])) {
        minvertex = i;
      }
    }

    return minvertex;
  }

  void Prims() {
    bool *visited = new bool[v];  // mapping for visited vertices
    int *parent = new int[v];
    int *weight = new int[v];

    for (int i = 0; i < v; i++) {
      visited[i] = false;
      weight[i] = INT_MAX;
    }

    // there is no edge from parent to any other edge
    parent[0] = -1;
    // first node is visited so weight = 0
    weight[0] = 0;

    for (int i = 0; i < v; i++) {
      // it will give the vertex which is not visited and weight of vertext is
      // min

      int minvertex = findminvertex(weight, visited, v);
      visited[minvertex] = true;
      // visiting the neighbours
      for (auto neighbours : adj[minvertex]) {
        if (!visited[neighbours.first]) {
          // if the weight for a vertex in mapping
          // is greater than weight at a particular edge  or not
          if (weight[neighbours.first] > neighbours.second) {
            parent[neighbours.first] = minvertex;
            weight[neighbours.first] = neighbours.second;
          }
        }
      }
    }

    for (int i = 0; i < v; i++) {
      cout << i << "--" << parent[i] << " with weight " << weight[i] << endl;
    }
  }
};

int main() {
  int n, e;
  cin >> n >> e;
  Graph g(n);
  for (int i = 0; i < e; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    g.addEdge(u, v, w);
  }

  g.Prims();

  return 0;
}
