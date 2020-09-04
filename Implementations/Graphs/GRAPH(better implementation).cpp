#include<iostream>
#include<vector>
using namespace std;

class Graph
{   
    public:
    int N;
    /*     :True -> directed
            False -> undirected*/
    bool directed;
    vector<vector<int>> adjList;
    /*Constructor initializing number of nodes
        by default graph is DIRECTED */
    Graph(int nodes,bool type = true)
    {
        this->directed = type;
        N = nodes;
        adjList.resize(N);
    }
 
    void add_Edge(int src,int dest)
    {   
        // if undirected graph
        if(!directed)
            adjList[dest].push_back(src);
        //this has to execute wheather directed or undirected
        adjList[src].push_back(dest);  
    }

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
    Graph g1(6,false);
    g1.add_Edge(0,1);
    g1.add_Edge(1,2);
    g1.add_Edge(2,0);
    g1.add_Edge(3,2);
    g1.add_Edge(2,1);
    g1.add_Edge(3,2);
    g1.add_Edge(4,5);
    g1.add_Edge(5,4);

    g1.print_graph();
    //{0,1},{1,2},{2,0},{2,1},{3,2},{4,5},{5,4}
    return 0;
}