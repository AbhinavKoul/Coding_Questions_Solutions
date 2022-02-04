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

#define v vector
// O(N2) Approach by going GREEDY APPROACH
int minCut(string A) {
    int n = A.size();
    
    //keep isPalindrome dp
    v<v<bool>> isPalin(n,v<bool>(n));
    
    //gap approach
    for(int g = 0;g<n;g++)
    {
        for(int i = 0,j=g; j<n ;j++,i++)
        {
            if(g==0)
                isPalin[i][j] = true;
            else if(g == 1)
            {
                if(A[i] == A[j])
                    isPalin[i][j] = true;
                else
                    isPalin[i][j] = false;
            }
            else
            {
                if(A[i] == A[j])
                    isPalin[i][j] = isPalin[i+1][j-1];
                else
                    isPalin[i][j] = false;
            }
        }
    }
    
    //finding min cuts in 1D array
    v<int> dp(n);
    dp[0] = 0;
    
    
    for(int i = 1;i<n;i++)
    {
        if(isPalin[0][i])
        {
            dp[i] = 0;
            continue;
        }    
        
        int mini = INT_MAX;
        for(int j = i;j>0;j--)
        {
            if(isPalin[j][i])
                mini = min(mini,dp[j-1]);
        }
        
        dp[i] = mini + 1;
    }
    
    return dp[n-1];

}
// Naive MCM Solution O(N3) Approach
/*
why we should have one more matrix that keeps track of palindrome;

test case
"c ababa bcb c"

now this result wont be 1(answer of middle) cause it wont make a plaindrome

rather it would be 1 + 2(cuts)

--> thus only for palindrome we can copy middle element cuts, for all others we need to solve
*/
int Solution::minCut(string A) {
    int n = A.size();
    
    v<v<int>> dp(n,v<int>(n));
    
    //gap diagonal appraoch
    for(int g = 0;g<n;g++)
    {
        for(int i = 0,j = g;j<n;i++,j++)
        {
            if(g == 0)
                dp[i][j] = 0;
            else if(g == 1)
            {
                if(A[j] == A[i])
                    dp[i][j] = 0;
                else
                    dp[i][j] = 1;
            }
            else
            {
                if(A[i] == A[j])
                {
                    if(dp[i+1][j-1] == 0)
                        dp[i][j] = dp[i+1][j-1];
                    else
                    {
                        int mini = INT_MAX;
                        for(int k = i;k<j;k++)
                        {
                            mini = min(mini,dp[i][k] + dp[k+1][j]);
                        }
                        dp[i][j] = mini + 1;
                    }
                }
                    
                else
                {
                    int mini = INT_MAX;
                    for(int k = i;k<j;k++)
                    {
                        mini = min(mini,dp[i][k] + dp[k+1][j]);
                    }
                    dp[i][j] = mini + 1;
                }
            }
        }
    }
    
    return dp[0][n-1];
}
