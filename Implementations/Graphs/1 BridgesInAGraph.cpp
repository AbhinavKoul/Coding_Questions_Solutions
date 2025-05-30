#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define v vector
// https://www.youtube.com/watch?v=2rjZH0-2lhk&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=25
void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<v<int>>& adj) {
    
    vis[node] = 1; 
    tin[node] = low[node] = timer++; 
    for(auto it: adj[node]) {
        if(it == parent) continue;
        
        if(!vis[it]) {
            dfs(it, node, vis, tin, low, timer, adj); 
            low[node] = min(low[node], low[it]); 
            if(low[it] > tin[node]) {
                cout << node << " " << it << endl;
            }
        } else {
            low[node] = min(low[node], tin[it]); 
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m; 
	vector<v<int>> adj(n); 
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v; 
	    adj[u].push_back(v);
	    adj[v].push_back(u); 
	}
	
	vector<int> tin(n, -1);
	vector<int> low(n, -1); 
	vector<int> vis(n, 0); 
	int timer = 0; 
	for(int i = 0;i<n;i++) {
	    if(!vis[i]) {
	        dfs(i, -1, vis, tin, low, timer, adj); 
	    }
	}
	
	return 0;
}