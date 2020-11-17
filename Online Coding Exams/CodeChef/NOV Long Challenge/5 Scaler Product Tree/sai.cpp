#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
#define v vector
#define um unordered_map
#define endl "\n"
#define pb push_back
#define mod 4294967296


using namespace std;



void dfs(signed int source,signed int parent,vector<bool > &seen, vector< vector<signed int> > &adjList, vector< vector<signed int> > &forceVector,vector<signed int>weights)
{
    seen[source]=true;

    if(source==1)
        forceVector[source].pb(weights[source]);
    else
    {
        forceVector[source]=forceVector[parent];
        forceVector[source].pb(weights[source]);
    }

    for(auto x: adjList[source])
        if(seen[x]==false)
            dfs(x,source,seen,adjList,forceVector,weights);
}

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,Q;
    cin>>N>>Q;

    v<signed int> weights(N+1);


    for(int i=1;i<=N;i++)
        cin>>weights[i];

    v<v<signed int>>forceVector(N+1);

    v<v<signed int >>adjList(N+1);

    v<bool>seen(N+1,false);



    signed int edges =N-1;
    signed int x,y;

    while(edges--)
    {
        cin>>x>>y;

        adjList[x].pb(y);
        adjList[y].pb(x);
    }

    dfs(1,1,seen,adjList,forceVector,weights);


    signed int q1,q2,len;
    long long ans=0;
    for(int i=0;i<Q;i++)
    {
        cin>>q1>>q2;

        len=forceVector[q1].size();
        ans=0;
        
        for(int i=0;i<len;i++)
            ans+=(((forceVector[q1][i])%mod)*(forceVector[q2][i]%mod))%mod;
        
        cout<<ans%mod<<endl;
    }
   

   
}