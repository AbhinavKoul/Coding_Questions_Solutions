class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size(),i,j,temp;
        //transpose the matrix
        for(int i = 0; i<n; i++){
     		// j start from i, because we already tranposed previous row, col
            for(int j = i; j<n; j++){
                //swap row column
                swap(matrix[i][j], matrix[j][i]);
                
            }
        }
        for (i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};