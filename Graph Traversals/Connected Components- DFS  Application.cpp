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

    void dfsHelper(int node, map<int, bool> &visited)
    {

        visited[node] = true;
        cout<< node << "-->" ;
        for(auto i : l[node])
        {

            if(!visited[i])
                dfsHelper(i,visited);
        }



    }

    void dfs(int src)
    {

        map<int , bool> visited;

     dfsHelper(src, visited);
     cout<<endl;


      int component=1;

        for(auto i : l)
        {
            int no=i.first;

            if(!visited[no])
            {

                dfsHelper(no, visited);
                component++;
            }
        }

        cout<< " The graph as " << component << " components";


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
    // Extra component added with no link in the previous graph
    g.AddEdge(7,8);

    g.dfs(0);
    return 0;


}

