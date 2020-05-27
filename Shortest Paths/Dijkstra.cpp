
#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Graph {
  unordered_map<T, list<pair<T, int>>> m;

 public:
  void addEdge(T u, T v, int dist, bool birdir = true) {
    m[u].push_back(make_pair(v, dist));
    if (birdir) m[v].push_back(make_pair(u, dist));
  }

  void printAdj() {
    // Iterate over all the key value pairs of the map
    for (auto j : m) {
      cout << j.first << "-->";
      for (auto l : j. second) {
        cout << "(" << l.first << "," << l.second << ")";
      }
      cout << endl;
    }
  }
  void Dijsktrasssp(T src) {
    unordered_map<T, int> dist;
    // set all distance to inf
    for (auto j : m) {
      dist[j.first] = INT_MAX;
    }
    // make a set to find node with  min distance
    set<pair<int, T>> s;
    dist[src] = 0;
    s.insert(make_pair(0, src));

    while (!s.empty()) {
      // find pair at front

      auto p = *(s.begin());
      T node = p.second;
      int nodedist = p.first;
      s.erase(s.begin());
      // iterate neighbour of current node

      for (auto childpair : m[node]) {
        if (nodedist + childpair.second < dist[childpair.first]) {
          // in the set  updation of a particular is not possiblr
          // we have to remove the old pair and insert new pair
          T dest = childpair.first;
          auto f  = s.find(make_pair(dist[dest], dest));
          if (f != s.end()) {
            s.erase(f);
          }

          // insert the new pair

          dist[dest] = nodedist + childpair.second;
          s.insert(make_pair(dist[dest], dest));
        }
      }
    }

    // print
    for (auto d : dist) {
      cout << d.first << " is located at distance of " << d.second << endl;
    }
  }
};

int main() {
  Graph<int> g;
  g.addEdge(1, 2, 1);
  g.addEdge(1, 3, 4);
  g.addEdge(2, 3, 1);
  g.addEdge(3, 4, 2);
  g.addEdge(1, 4, 7);
  g.printAdj();
  g.Dijsktrasssp(1);

  return 0;
}
