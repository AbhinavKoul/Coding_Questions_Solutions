//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
#define v vector

using namespace std;
class Solution {
public:
    int n,m,size; vector<vector<char>> bd; string wd;
    
    bool dfs(int i,int j,int f,vector<vector<bool>> &vis)
    {
        if(f==size-1) 
            return true;
        
        if(!vis[i][j]) 
        {
            vis[i][j]=true;

            if( i+1<n && !vis[i+1][j] && bd[i+1][j]==wd[f+1] && dfs(i+1,j,f+1,vis)) 
                return true;
            
            if( j+1<m && !vis[i][j+1] && bd[i][j+1]==wd[f+1] && dfs(i,j+1,f+1,vis)) 
                return true;
            
            if( i-1>=0 && !vis[i-1][j] && bd[i-1][j]==wd[f+1] && dfs(i-1,j,f+1,vis)) 
                return true;
            
            if( j-1>=0 && !vis[i][j-1] && bd[i][j-1]==wd[f+1] && dfs(i,j-1,f+1,vis)) 
                return true;
            
            vis[i][j]=false;
            return false;
        }
        else
            return false;
        
    
    }
    bool exist(vector<vector<char>>& board, string word) {

        n=board.size(), 
        m=board[0].size(), 
        size=word.size(); 
        bd=board; 
        wd=word;

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0] && dfs(i,j,0,vis)) 
                    return true;
            }
        }
        
        return false;
    }
};