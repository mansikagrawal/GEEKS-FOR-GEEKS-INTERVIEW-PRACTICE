#include<bits/stdc++.h>
using namespace std;

class Graph{


    unordered_map<int , list<int>> l;
public:
    Graph()
    {
    }

    void AddEdge(int x, int y, bool bidir)
    {
        l[x].push_back(y);
        if(bidir)
        l[y].push_back(x);
    }

    int  bfs(int src, int dest)
    {
        queue<int> q;
        map<int , int> dist;
        map<int , int > parent;

        for ( auto i : l)
        {

            dist[i.first] = INT_MAX;
        }
        q.push(src);
        dist[src]=0;
        parent[src] = src;

        while(!q.empty())
        {
            int node=q.front();
         //  cout<<node<<" ";
            q.pop();


            // explore neighbours

            for(int neighbours:l[node])
            {

                if(dist[neighbours] > dist[node]+1)
                {
                    q.push(neighbours);
                    dist[neighbours]=dist[node] +1;
                    parent[neighbours] = node;


                }


            }

        }
        return dist[dest];

    }


};



int main()
{

    int t;
    cin>>t;



    while(t--)
    {
        int v[200]={0};
		int k=0;
        int ladders;
        cin>> ladders;


        for(int i=0; i< ladders ; i++)
        {

            int x; int y;
            cin>> x >> y;
            v[x]=(y-x);


        }

        int snakes;
        cin>> snakes;

        for(int i=0; i < snakes;i++)
        {

            int x ; int y;
            cin>> x>> y;
            v[x]=(y-x);
        }


        /* for(int i=0; i < k;i++)
            cout<< v[i] << " "; */
            Graph g;

            for(int u=1; u <= 100; u++)
            {

                for( int dice = 1 ; dice <= 6; dice++) {

                    int ver = u + dice + v[dice+u];
                    g.AddEdge(u, ver, false);

                }
            }

			int ans= g.bfs(1,100) ;
			if(ans==INT_MAX){ cout<<-1<<endl; }
			else{ cout<<ans<<endl; }

    }


    return 0;


}
