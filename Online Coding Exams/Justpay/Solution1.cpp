#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
using namespace std;
#define v vector


v<v<int>> adjList;
unordered_map<int,int> um;

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
bool isPath(int src,int dest,const int& N)
{
    v<bool> visited(N+1,false);
    
    return dfsUtil(src,dest,visited);
}

int main()
{
    int N;
    cin>>N;
    um.clear();
    adjList.clear();
    adjList.resize(N+1);

    //map banao
    for(int i = 1;i<=N;i++)
    {
        int id;
        cin>>id;
        um[id] = i;
    }

    int edges;
    cin>>edges;

    for(int i =0;i<edges;i++)
    {
        int src,dest;

        cin>>src>>dest;
        adjList[um[src]].push_back(um[dest]);
    }

    int A,B;
    cin>>A;
    cin>>B;

    
    if(isPath(um[A],um[B],N))
        cout<<"1";
    else
        cout<<"0";
}