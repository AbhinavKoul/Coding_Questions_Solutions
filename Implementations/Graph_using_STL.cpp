#include<iostream>
#include<vector>
using namespace std;

struct Edge
{
    int src,dest;
};

class Graph
{
    public:
    //adjacency list
    vector<vector<int>> adjList;
    //no of nodes
    int N;
    //constructor for directed graph
    Graph(vector<Edge> const &edges,int nodes)
    {
        N = nodes;
        //resize adjList to no of nodes
        adjList.resize(N);
        
        //add edges to adjacency list
        for(auto &edge : edges)
        {
            //insert at end
            adjList[edge.src].push_back(edge.dest);
        }
    }
    //print graph in adjacency list representation
    void print_graph()
    {
        for(int i=0;i<N;i++)
        {
            //print src vertex
            cout<<i<<"-->";
            for(int V : adjList[i])
                cout<<V<<" ";
            cout<<endl;
        }
    }
};

int main()
{
    //initilize edge vector
    vector<Edge> edges = {
        {0,1},{1,2},{2,0},{2,1},{3,2},{4,5},{5,4}
    };
    //nodes
    int N = 6;

    //construct Graph
    Graph graph(edges,6);
    //print
    graph.print_graph();

    return 0;
}