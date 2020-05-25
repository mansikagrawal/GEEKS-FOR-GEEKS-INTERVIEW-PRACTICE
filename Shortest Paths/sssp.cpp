#include <bits/stdc++.h>
using namespace std;

class Graph {
  unordered_map<int, list<int>> l;

 public:
  Graph() {}

  void AddEdge(int x, int y) {
    l[x].push_back(y);
    l[y].push_back(x);
  }

  void bfs(int src) {
    queue<int> q;
    map<int, int> dist;

    q.push(src);

    for (auto node_pair : l) {
      int node = node_pair.first;
      dist[node] = INT_MAX;
    }
    dist[src] = 0;

    while (!q.empty()) {
      int node = q.front();
      q.pop();


          // explore neighbours

          for (int neighbours : l[node]) {
        if (dist[neighbours] == INT_MAX) {
          q.push(neighbours);
          dist[neighbours] = dist[node] + 1;
        }
      }
    }

    for (auto node_pair : l) {
      int node = node_pair.first;
      int d = dist[node];
      cout << "Node " << node << " Dist from src " << d << endl;
    }
  }
};

int main() {
  Graph g;
  g.AddEdge(0, 1);
  g.AddEdge(0, 4);
  g.AddEdge(2, 1);
  g.AddEdge(2, 4);
  g.AddEdge(4, 3);
  g.AddEdge(5, 3);
  g.AddEdge(2, 3);

  g.bfs(0);
  return 0;
}
