// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

bool isCycle(int v, vector<bool> &visited, vector<bool>&recStack, int n, vector<vector<int>> &adj)
{
    if(!visited[v])
    {
        visited[v]=true;
        recStack[v]=true;
    

    for( auto i : adj[v])
    {
        if(!visited[i] && isCycle(i, visited, recStack, n, adj))
        {
            return true;
        }
        else if(recStack[i]){

            int flag=0;
            for(int i=1;i<n;i++)
            {
                if(recStack[i]==false)
                {
                    flag=1;
                }

            }

            if(flag==0)
                return true;
            

        }
    }
    }


    recStack[v]=false;
    return false;

}
bool solution(vector<int> &A, vector<int> &B) {

    int n=A.size();

    vector<vector<int>> adj(n+1);

    for(int i=0;i<n;i++)
    {
        adj[A[i]].push_back(B[i]);

    }

    vector<bool> visited(n+1,false);
    vector<bool> recStack(n+1,false);

    // for(int i = 1;i<=n;i++)
    // {
        if(isCycle(4,visited, recStack,n,adj))
            return true;
    // }
    

    return false;

}
int main()
{
    vector<int> arr = {1,2,3,4,2};
    vector<int> B = {2,4,1,3,3};
    cout<<"heloo : "<<solution(arr,B);
}