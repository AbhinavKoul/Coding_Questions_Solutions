#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define v vector


v<v<int>> adjList;
bool dfsUtil(int node,const int dest,v<bool> &visited)
{
    
    visited[node] = true;
        
    for(auto i : adjList[node])
    {
        if(!visited[i])
        {
            if(i == dest)
                return true;
            if(dfsUtil(i,dest,visited)) //dont do directly return!!!! CAUSE THEN IT WILL RETURN FALSE ALSO DOWN SOME PATH!
                return true; 
        }
            
    }
    
    return false;
        
}
bool isPath(int src,int dest)
{
    v<bool> visited(dest+1,false);
    
    return dfsUtil(src,dest,visited);
}
int solve(int A, vector<vector<int>> &B) {
    adjList.clear();
    adjList.resize(A+1);
    
    for(auto i : B)
    {
        int src = i[0];
        int dest = i[1];
        adjList[src].push_back(dest);
    }
    
    
    if(isPath(1,A))
        return 1;

    return 0;
}
