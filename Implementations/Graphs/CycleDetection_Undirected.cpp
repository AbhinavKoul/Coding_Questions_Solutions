#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define v vector

v<v<int>> adjList;

bool check_cycle(int node,int parent,v<bool> &visited)  //mine approach
{
    if(!visited[node])
    {
        visited[node] = true;
        for(auto i : adjList[node])
        {
            if(i != parent)
                if(check_cycle(i,node,visited)) return 1;
                else
                    check_cycle(i,node,visited);
        }
    }
    else
        return 1;

    
    return 0;
}
    
bool check_cycle(int node,int parent,v<bool> &visited)  //aman.........
{                                                       
    visited[node] = true;
    
    for(auto i : adjList[node])
    {
        if(i != parent)
        {
            if(visited[i])
                return true;
            if(!visited[i] && check_cycle(i,node,visited))
                return true;
        }
    }
    
    return false;
}

int solve(int A, vector<vector<int> > &B) {
    adjList.clear();
    adjList.resize(A+1);

    for(auto i : B)
    {
        int src = i[0];
        int dest = i[1];
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    v<bool> visited(A+1,false);

    for(int i = 1;i<=A;i++)
    {
        if(!visited[i] && check_cycle(i,-1,visited))
            return 1;
    }
    
    return 0;


}