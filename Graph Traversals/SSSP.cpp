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

    void bfs(int src)
    {
        queue<int> q;
        map<int , int> dist;
        map<int, int> parent;

        for(auto i:l)
        {

            dist[i.first]=INT_MAX;
        }

        q.push(src);
        dist[src]=0;
        parent[src]= src;

        while(!q.empty())
        {
            int node=q.front();
            cout<<node<<" ";
            q.pop();


            // explore neighbours

            for(int neighbours:l[node])
            {

                if(dist[neighbours]==INT_MAX)
                {
                    q.push(neighbours);
                    dist[neighbours]=dist[node] + 1;
                    parent[neighbours] = node;


                }


            }

        }
        cout<<endl;

        for ( auto i: l){
                int node = i.first;
            cout<<"Distance of " <<node << " from " <<  src << " is " << dist[node]<<endl;}

    }


};



int main()
{


    Graph g;
    g.AddEdge(0,1);
    g.AddEdge(0,4);
    g.AddEdge(2,1);
    g.AddEdge(2,4);
    g.AddEdge(4,3);
    g.AddEdge(5,3);
    g.AddEdge(2,3);

    g.bfs(0);

    return 0;


}
