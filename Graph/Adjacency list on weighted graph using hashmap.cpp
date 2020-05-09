#include <bits/stdc++.h>
using namespace std;
class Graph
{



    public:

    unordered_map<string, list<pair<string, int >>> l;
    void addEdge(string x, string y, bool bidirectional, int amt)
    {
        l[x].push_back(make_pair(y,amt));
        if(bidirectional)
         l[y].push_back(make_pair(x,amt));


    }

    void printEdge()
    {


        for(auto node : l)
        {

            string vertex=node.first;
            list<pair<string, int >> nbrs =node.second;
            cout<<"Vertex " << vertex<<"-->";

            for(auto nbr:nbrs)
            {
                string node =nbr.first;

                int dist = nbr.second;
            cout<<node<< " "<< dist<< " ,";

            }
            cout<<endl;

        }

    }


};
int main() {


	Graph g;
	g.addEdge("A" , "B",false,20);
	g.addEdge("A" , "C" , true, 10);
	g.addEdge("A","D",false,20);
	g.addEdge("B","D",true,30);
	g.addEdge("C", "D", true, 40);
	g.printEdge();
	return 0;
}
