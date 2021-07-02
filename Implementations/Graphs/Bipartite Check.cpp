#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define v vector
// BIPARTITE USING BFS APPROACH!!

class Solution {
public:
    bool bfsCheck(int src,v<int> &color,vector<int> adj[])
    {
        queue<int> Q;
	    Q.push(src);
	    color[src] = 0;
	    
	    while(!Q.empty())
	    {
	        int k = Q.front(); Q.pop();
	        
	        for(auto i : adj[k])
	        {
	            if(color[i] == -1)
	            {
	                color[i] = 1 - color[k];
	                Q.push(i);
	            }
	            else if(color[i] == color[k])   //same color
	                return false;
	        }
	    }
	    
	    return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    v<int> color(V,-1);
	    
	    for(int i = 0;i<V;i++)
	    {
	        if(color[i] == -1)
	        {
	            if(!bfsCheck(i,color,adj))
	                return false;
	        }
	    }
	    
	    
	    return true;
	    
	}

};