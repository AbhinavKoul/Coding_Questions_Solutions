#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define v vector

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
    
    bool isCyclicUtil(int V,v<bool> &visited,v<bool> &recStack)
    {
        if(!visited[V])
        {
            //mark it as visted and in recStack
            visited[V] = true;
            recStack[V] = true;
            
            //all next vertices recur like in dfs
            for(auto i : adjList[V])
            {
                if(!visited[i] && isCyclicUtil(i,visited,recStack))
                    return true;
                else if(recStack[i])
                    return true;
            }
        }
        recStack[V] = false; //remove vertex from recStack
        
        return false;
    }
    
    bool isCyclic()
    {
        // mark all nodes as non-visited
        vector<bool> visited(N,false);
        v<bool> recStack(N,false);
        
         // Call the recursive helper function to detect cycle in different
        // DFS trees
        for(int i = 0; i < N; i++)
            if (isCyclicUtil(i, visited, recStack))
                return true;

        return false;
    }
    
        // A recursive function used by topologicalSort
    void topologicalSortUtil(int V, v<bool> &visited, stack<int>& Stack)
    {
        // Mark the current node as visited.
        visited[V] = true;

        // Recur for all the vertices
        // adjacent to this vertex
        for (auto i : adjList[V])
            if (!visited[i])
                topologicalSortUtil(i, visited, Stack);

        // Push current vertex to stack
        // which stores result
        Stack.push(V);
    }

    // The function to do Topological Sort.
    // It uses recursive topologicalSortUtil()
    stack<int> topologicalSort()
    {
        stack<int> Stack;

        v<bool> visited(N,false);

        // Call the recursive helper function
        // to store Topological
        // Sort starting from all
        // vertices one by one
        for (int i = 0; i < N; i++)
            if (!visited[i])
                topologicalSortUtil(i, visited, Stack);

        return Stack;
    }
};
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Graph g1(numCourses);
        
        for(auto v : prerequisites)
            g1.add_Edge(v[1],v[0]);
        
        if(g1.isCyclic())
            return false;
        
        // now if it is a DAG, then we need to see topological sorting
        
        stack<int> s1 = g1.topologicalSort();
        
        if(s1.size() == numCourses)
            return true;
        else
            return false;
        
        
    }
};