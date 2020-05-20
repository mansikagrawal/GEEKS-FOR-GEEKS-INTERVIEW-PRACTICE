#include<bits/stdc++.h>
using namespace std;


template<typename T>
class Graph
{
    map<T, list<T>> l;
public:
    void addEdge(T x, T y)
    {
        l[x].push_back(y);


    }
    void dfs_Helper(T src, map<T, bool> &visited,list<T> &ordering )
    {

        visited[src] = true;

        for(auto nei:l[src])
        {
        if(!visited[nei])
        {

            dfs_Helper(nei,visited,ordering);
        }

        }
        ordering.push_front(src);
        return;

    }


    void dfs(){


    map<T, bool> visited;
    list<T> ordering;

    for(auto p:l)
    {

        T node=p.first;
        visited[node] = false;
    }

    for(auto p: l)
    {

         T node= p.first;
         if(!visited[node])
         {

             dfs_Helper(node, visited, ordering);
         }
    }
    for(auto x: ordering)
        cout<< x << " ";


    }



};


int  main()
{

    Graph<int> g;

    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.dfs();

    return 0;

}
