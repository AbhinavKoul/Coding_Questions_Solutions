#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct Edge
{
    int src,dest;
};
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

    //constructor if edges given in a list
    //constructor for directed graph
    Graph(vector<Edge> const &edges,int nodes)
    {
        N = nodes;
        //resize adjList to no of nodes
        adjList.resize(N);
        
        //add edges to adjacency list
        for(auto &edge : edges)
        {
            //insert
            add_Edge(edge.src,edge.dest);
        }
    }

    void DFSUtil(int V,vector<bool> &visited)
    {
        //make the current node as visited
        visited[V] = true;
        cout<< V << " ";
        // Recur for all the vertices adjacent 
        // to this vertex
        for(auto i : adjList[V]) 
        {
            if(!visited[i])
                DFSUtil(i,visited);
        }
    }
    // DFS traversal of the vertices reachable from v. 
    // It uses recursive DFSUtil() 
    void DFS(int V)
    {   
        // mark all nodes as non-visited
        vector<bool> visited(N,false);
        //go through each nodes connected to V (WHEN GRAPH IS CONNECTED)
        DFSUtil(V,visited);

        /*
            WHEN GRAPH IS NOT CONNECTED!!!!!!!!!!!!!!1
        */
        // Call the recursive helper function to print DFS
        // traversal starting from all vertices one by one
        // for (int i = 0; i < V; i++)
        //     if (visited[i] == false)
        //         DFSUtil(i, visited);
    }
    // prints all unvisited vertices directly connected to vertex V
    void BFSUtil(int V,vector<bool> &visited)
    {
        

        //create a queue for BFS
        queue<int> Q;

        // Mark the source node as visited and enqueue it 
        visited[V] = true; 
        Q.push(V);
        // while queue is not empty
        while(!Q.empty())
        {   
            //dequeue vertex from queue
            int f = Q.front();
            Q.pop();
            //print the recently dequed vertex
            cout<<f<<" ";

            // Enqueue all adjacent of f and mark them visited
            for(auto i : adjList[V])
            {
                if(!visited[i])
                {
                    Q.push(i);
                    visited[i] = true;
                }
            }
        }

    }
    //BFS transversal starting from a src node
    void BFS(int src)
    {
        // mark all nodes as non-visited
        vector<bool> visited(N,false);

        // we only see all those nodes which are adjacent to the source node
        for(auto x: adjList[src])
        {
            if(!visited[x])
                BFSUtil(x,visited);
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
    Graph g1(7);
    g1.add_Edge(0,1);
    g1.add_Edge(0,2);
    g1.add_Edge(1,3);
    g1.add_Edge(1,4);
    g1.add_Edge(2,5);
    g1.add_Edge(2,6);

    //g1.print_graph();
     g1.DFS(0);
    // cout<<endl;
    // g1.DFS(2);
    // cout<<endl;
    g1.BFS(1);
    //{0,1},{1,2},{2,0},{2,1},{3,2},{4,5},{5,4}
    return 0;
}
