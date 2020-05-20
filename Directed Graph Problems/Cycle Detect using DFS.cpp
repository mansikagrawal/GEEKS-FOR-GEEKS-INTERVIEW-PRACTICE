#include<bits/stdc++.h>
using namespace std;

class Graph
{
 list<int> *l;
 int V;

 public:
     Graph(int V)
     {
         this-> V=V;
         l=new list<int>[V];

     }
     void addEdge(int x, int y)
     {

         l[x].push_back(y);

     }


     bool cycle_Helper(int node , bool *visited, bool *stack)
     {
         //visit a node
         visited[node] = true;
         stack[node] = true;



          for(int nbr:l[node])
          {
              //Two cases
              if(stack[nbr] == true)
                return true;

              // neighbout is not visited but thos neighbour can lead a cycle
              else if(visited[nbr] == false){
                bool cycle_mila=cycle_Helper(nbr,visited,stack);
                if(cycle_mila==true)
                    return true;

              }

          }





         //leave node
         stack[node] = false;
         return false;

     }

     bool contain_cycle()
     {
         bool *visited=new bool[V];
         bool  *stack = new bool[V];

         for(int i=0;i < V;i++)
         {

             visited[i]=stack[i]=false;
         }
         return cycle_Helper(0,visited,stack);

     }



};


int main()
{

    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,5);
    g.addEdge(2,3);
    g.addEdge(4,5);
    g.addEdge(3,4);
    g.addEdge(5,6);
    g.addEdge(4,2);
    bool ans= g.contain_cycle();
    if(ans==true)
    cout<<"Cycle Present";
    else
    cout<< " No cycle";


    return 0;



}
