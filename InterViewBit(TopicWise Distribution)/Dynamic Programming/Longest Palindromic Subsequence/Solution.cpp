#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
#define v vector
#define um unordered_map
#define mod 1000000007
#define ll long long int
using namespace std;

// https://www.youtube.com/watch?v=RiNzHfoA2Lo

//BEST WRITING WAY
#define v vector
int solve_BEST_way(string A) 
{
    int n = A.length();
 
    v<v<int>> dp(n,v<int>(n));
 
    
    //go for gap diagonals 
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
            }
        }
    }
    
    return dp[0][n-1];
}
//MY SOLUTION
int solve(string A) {
    int n = A.length();

    v<v<int>> dp(n,v<int>(n,0));
    for(int i = 0;i<n-1;i++)
    {
        dp[i][i] = 1;   //0 diagonal
        
        //1st gap diagonal
        if(A[i] == A[i+1])
            dp[i][i+1] = 2;
        else
            dp[i][i+1] = 1;
    }    
    
    dp[n-1][n-1] = 1;
    //go for gap diagonals
    for(int g = 2;g<n;g++)
    {
        for(int i = 0,j=g ; j<n; i++,j++)
        {
            if(A[i] == A[j])
                dp[i][j] = dp[i+1][j-1] + 2;    //middle ope + 2
            else
                dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
        }
    }
    
    return dp[0][n-1];
}
