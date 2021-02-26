// { Driver Code Starts
//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
#define v vector

using namespace std;

 // } Driver Code Ends


class Solution {
public:
    void dfs(int i,int j,vector<vector<bool>> &visited,int m,int n,vector<vector<int>>& grid)
    {
        while(!visited[i][j])
        {
            if(grid[i][j] == 0)
                return;
            
            visited[i][j] = true;
            if(grid[i][j] == 2)
                return;
            //top row
            if(i == 0)
            {
                //if left corner
                if(j == 0)
                {
                    dfs(i+1,j,visited,m,n,grid);
                    dfs(i,j+1,visited,m,n,grid);
                }
                else if(j == n-1)
                {
                    dfs(i+1,j,visited,m,n,grid);
                    dfs(i,j-1,visited,m,n,grid);
                }
                else
                {
                    dfs(i+1,j,visited,m,n,grid);
                    dfs(i,j+1,visited,m,n,grid);
                    dfs(i,j-1,visited,m,n,grid);
                }
            }
            //bottom row
            else if(i == m-1)
            {
                if(j == 0)
                {
                    dfs(i-1,j,visited,m,n,grid);
                    dfs(i,j+1,visited,m,n,grid);
                }
                else if(j == n-1)
                {
                    dfs(i-1,j,visited,m,n,grid);
                    dfs(i,j-1,visited,m,n,grid);
                }
                else
                {
                    dfs(i-1,j,visited,m,n,grid);
                    dfs(i,j+1,visited,m,n,grid);
                    dfs(i,j-1,visited,m,n,grid);
                }
            }
            //left col
            else if(j == 0)
            {
                dfs(i-1,j,visited,m,n,grid);
                dfs(i,j+1,visited,m,n,grid);
                dfs(i+1,j,visited,m,n,grid);
            }
            //right col
            else if(j == n-1)
            {
                dfs(i-1,j,visited,m,n,grid);
                dfs(i,j-1,visited,m,n,grid);
                dfs(i+1,j,visited,m,n,grid);
            }
            else
            {
                dfs(i-1,j,visited,m,n,grid);
                dfs(i+1,j,visited,m,n,grid);
                dfs(i,j+1,visited,m,n,grid);
                dfs(i,j-1,visited,m,n,grid);
            }
        }
    }
    bool is_Possible(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        pair<int,int> start_pos;   
        pair<int,int> dest_pos;
        for(int i = 0;i<m;i++)
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    start_pos.first = i;
                    start_pos.second = j;
                }
                
                if(grid[i][j] == 2)
                {
                    dest_pos.first = i;
                    dest_pos.second = j;
                }
            }
        
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        dfs(start_pos.first,start_pos.second,visited,m,n,grid);
        
        
        if(visited[dest_pos.first][dest_pos.second])
            return true;
        else
            return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends