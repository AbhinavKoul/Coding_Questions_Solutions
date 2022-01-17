//this automatically take care of not valid entries in bottom diagonal of the matrix

v<v<int>> dpt(n, v<int>(n, 0));
for(int g = 0;g<n;g++)                 
{
    for(int i = 0,j=g; j<n; i++,j++)
    {
        if(g==0)    // single char is always palindromic
            dp[i][j] = 1;
        else if(g==1)   //1 gap diagonal
        {
            if(A[i] == A[j])
                dp[i][j] = 2;
            else
                dp[i][j] = 1;
        }
        else    //for all the other gap diagonals
        {
            if(A[i] == A[j])
                dp[i][j] = dp[i+1][j-1] + 2;    //middle ope + 2
            else
                dp[i][j] = max(dp[i][j-1],dp[i+1][j]);



            ------------------------ ONE MORE --------------------------- 
            1. Matrix Chain Multlipication
            2. Min Cut Palindrome
            3. Boolean Paranthesis
            
            for(int k = i;k<j;k++)
            {
                int left = dp[i][k];
                int right = dp[k+1][j];
            }
        }
    }
}