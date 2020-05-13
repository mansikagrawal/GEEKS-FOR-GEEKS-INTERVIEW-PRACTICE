#include<bits/stdc++.h>
using namespace std;

class Graph{

unordered_map<int , list<int>> l;
public:
    Graph()
    {
    }

    void AddEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    bool iscyclic(int src)
    {
        queue<int> q;
        map<int , bool> visited;
        map<int, bool> parent;


        q.push(src);
        visited[src]=true;
        parent[src] = src;

        while(!q.empty())
        {
            int node=q.front();

            q.pop();


            // explore neighbours

            for(int neighbours:l[node])
            {

                if(visited[neighbours] == true && parent[node] !=neighbours)
                    return true;

                 else if(!visited[neighbours])
                {
                    q.push(neighbours);
                    visited[neighbours]=true;
                    parent[neighbours] = node;


                }


            }

        }

        return false;

    }


};



int main()
{


    Graph g;
    g.AddEdge(0,1);
    g.AddEdge(0,4);
    g.AddEdge(2,1);
   g.AddEdge(2,4);


    if(g.iscyclic(0))
    cout<<" Cycle is Present";
    else
    cout<<" No cycle Present";
    return 0;


}
