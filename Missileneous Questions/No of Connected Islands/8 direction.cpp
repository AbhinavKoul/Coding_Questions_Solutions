#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define v vector
class Solution {
public:
    
    bool isSafe(const v<v<char>> &grid,const v<v<bool>> &visited,int i,int j)
    {
        int r = grid.size();
        int c = grid[0].size();
        //
        bool limits = (i>=0 && i<r) && (j>=0 && j<c);
        return(limits && !visited[i][j] && grid[i][j] == '1');
    }
    
    void bfs(const v<v<char>> &grid,v<v<bool>> &visited,int i,int j)
    {
        //relative positions of all 8 cells wrt current
        v<int> row = {-1,-1,-1,0,0,1,1,1};
        v<int> col = {-1,0,1,-1,1,-1,0,1};
        queue<pair<int,int>> Q;
        Q.push(make_pair(i,j));
        visited[i][j] = true;
        
        while(!Q.empty())
        {
            int r,c;
            tie(r,c) = Q.front();
            Q.pop();
            
            for(int k = 0;k<8;k++)
            {
                int row_neighbour = r+row[k];
                int col_neighbour = c+col[k];
                if(isSafe(grid,visited,row_neighbour,col_neighbour))
                {
                    Q.push(make_pair(row_neighbour,col_neighbour));
                    visited[row_neighbour][col_neighbour] = true;
                }
            }
            
        }
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        v<v<bool>> visited(r,v<bool>(c,false));
        
        
        int strongly_connected = 0;
        for(int i =0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(!visited[i][j] && grid[i][j] == '1')
                {
                    bfs(grid,visited,i,j);
                    strongly_connected++;
                }
            }
        }
        
        return strongly_connected;
        
    }
};