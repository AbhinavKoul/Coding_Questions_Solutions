class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int i,j,m,n;
        int count=0;
        m=grid.size();
        if (m==0){
            return 0;
        }
        n=grid[0].size();
        for (i=0;i<m;i++){
            for (j=0;j<n;j++){
                if (grid[i][j]=='1'){
                    count+=1;
                    bfs(grid,i,j);
                }
            }
        }
        return count;
    }
    
    void bfs(vector<vector<char>>& grid,int i,int j){
        if (i<0 or j<0 or i>=grid.size() or j>=grid[0].size()){
            return;
        }
        if (grid[i][j]=='0'){
            return;
        }
        else{
            
            grid[i][j]='0';
            bfs(grid,i+1,j);
            bfs(grid,i-1,j);
            bfs(grid,i,j+1);
            bfs(grid,i,j-1);
        }
    }
};