#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<queue>
using namespace std;
#define v vector



unordered_map<int,int> um;
typedef pair<int,int> ipair;
v<v<ipair>> adjList;

int shortestPath(int src,int dest,const int& N)
{
    priority_queue<ipair,v<ipair>,greater<ipair>> pq;
    v<int> distance(N+1,INT_MAX);

    pq.push(make_pair(0,src));  //mark source as 0 distance
    distance[src] = 0;

    while(!pq.empty())
    {
        int u = pq.top().second; pq.pop();

        for(auto i : adjList[u])
        {
            int v = i.first;
            int weight = i.second;

            if(distance[v] > distance[u] + weight)
            {
                distance[v] = distance[u] + weight;
                pq.push(make_pair(distance[v],v));
            }
        }
    }

    return distance[dest];
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
        int src,dest,wt;

        cin>>src>>dest>>wt;
        adjList[um[src]].push_back(make_pair(um[dest],wt));
    }

    int A,B;
    cin>>A;
    cin>>B;

    int res = shortestPath(um[A],um[B],N);
    cout<<res;
}