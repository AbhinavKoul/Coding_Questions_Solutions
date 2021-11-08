#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;
#define v vector

v<v<int>> adjList;
int solve(int N,v<int> A,v<int> B, v<int> H)
{
    adjList.resize(N);
    int m = A.size();
    for(int i = 0;i<m;i++)
    {
        adjList[A[i]].push_back(B[i]);
        adjList[B[i]].push_back(A[i]);
    }

    //modified dijkstra
    v<int> distance(N,99999);
    priority_queue<int,v<int>,greater<int>> pq;
    for(auto src: H)
    {
        pq.push(src);
        distance[src] = 0;

        while(!pq.empty())
        {
            int u = pq.top(); pq.pop();

            for(auto i : adjList[u])
            {
                if(distance[i] > distance[u] + 1)
                {
                    distance[i] = distance[u]+1;
                    pq.push(i);
                }
            }
        }

    }
    
    int ans = *max_element(distance.begin(),distance.end());

    if(ans == 9999)
        return -1;
    
    return ans;
}
int main()
{
    int N = 6;
    v<int> A = {0,1,1,3,0};
    v<int> B = {1,2,3,4,5};
    v<int> H = {2,4};

    cout<<"hello : "<<solve(N,A,B,H);
    return 0;
}