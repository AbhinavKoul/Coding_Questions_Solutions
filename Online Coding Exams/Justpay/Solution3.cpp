#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<set>
using namespace std;
#define v vector


v<v<int>> adjList;
unordered_map<int,int> um, invertUm;
set<int> possiblePeople;
set<int> res;

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
        int f = Q.front(); Q.pop();


        for(auto i : adjList[f])
        {
            if(!visited[i])
            {
                if(possiblePeople.count(i) == 1)
                    res.insert(i);
                Q.push(i);
                visited[i] = true;
            }
        }
    }

}
//BFS transversal starting from a src node
void BFS(int src,const int &N)
{
    // mark all nodes as non-visited
    vector<bool> visited(N+1,false);

    BFSUtil(src,visited);
}

void findPossibleFollowers(int dest,const int &N)
{
    v<v<int>> transposeAdjList(N+1);

    for(int i = 1;i<=N;i++)
    {
        for(auto it: adjList[i]) {
	        transposeAdjList[it].push_back(i); 
	    }
    }

    for(auto i : transposeAdjList[dest])
    {
        possiblePeople.insert(i);
    }
}
int main()
{
    int N;
    cin>>N;
    um.clear();
    adjList.clear();
    invertUm.clear();
    possiblePeople.clear();
    res.clear();
    adjList.resize(N+1);

    //map banao
    for(int i = 1;i<=N;i++)
    {
        int id;
        cin>>id;
        um[id] = i;
        invertUm[i] = id;
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

    findPossibleFollowers(um[B],N);

    BFS(um[A],N);
    
    cout<<endl;
    
    for(auto i : adjList[um[A]])
    {
        if(i == um[B])
        {
            res.insert(um[A]);
            break;
        }
            
    }
    for(auto i : res)
        cout<<invertUm[i]<<" ";
}