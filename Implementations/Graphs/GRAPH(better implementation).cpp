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

    void DFSUtil(int u,vector<bool> &visited)
    {
        //make the current node as visited
        visited[u] = true;
        cout<< u << " ";
        //go to all the connected nodes to current node
        for(int i = 0;i<adjList[u].size();i++)
        {
            //check if the node connected to src node is connected or not
            if(visited[adjList[u][i] == false])
            {
                //recursive call the fn for all the depth nodes    
                DFSUtil(adjList[u][i],visited);
            }
        }
    }

    void DFS()
    {   
        // mark all nodes as non-visited
        vector<bool> visited(N,false);
        //go through each nodes
        for(int u=0;u<N;u++)
        {   
            // if the current node is not still visited
            if(visited[u] == false)
                DFSUtil(u,visited);
        }
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
    Graph g1(5,false);
    g1.add_Edge(0,1);
    g1.add_Edge(0,4);
    g1.add_Edge(1,2);
    g1.add_Edge(1,3);
    g1.add_Edge(1,4);
    g1.add_Edge(2,3);
    g1.add_Edge(3,4);

    g1.print_graph();
    g1.DFS();
    //{0,1},{1,2},{2,0},{2,1},{3,2},{4,5},{5,4}
    return 0;
}