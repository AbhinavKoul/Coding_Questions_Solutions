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

#define v vector
//O(N2) --> Time
int solve_BEST_SOL(vector<int> &A, int B) 
{
    int n = A.size();
    B = min(n,B);
    v<v<int>> dp(B+1,v<int>(n));
    
    for(int i = 0;i<n;i++)
        dp[0][i] = 0;
        
    for(int i = 0;i<=B;i++)
        dp[i][0] = 0;
    
    //going for transsactions which we can do 
    for(int t = 1;t<=B;t++)
    {
        int maxPrevTransaction = INT_MIN;
        //going for days
        for(int d = 1;d<n;d++)
        {
            //keep updating this on rolling basis
            maxPrevTransaction = max(maxPrevTransaction,dp[t-1][d-1] - A[d-1]);
            
            dp[t][d] = max(dp[t][d-1],maxPrevTransaction + A[d]);
        }
    }
    
    return dp[B][n-1];
    
}

//O(N3)
int solve(vector<int> &A, int B) {
    int n = A.size();
    B = min(n,B);
    v<v<int>> dp(B+1,v<int>(n));
    
    for(int i = 0;i<n;i++)
        dp[0][i] = 0;
        
    for(int i = 0;i<=B;i++)
        dp[i][0] = 0;
    
    //going for transsactions which we can do 
    for(int t = 1;t<=B;t++)
    {
        //going for days
        for(int d = 1;d<n;d++)
        {
            int maxPrevTransaction = INT_MIN;
            //check for all previous days, with one less transaction
            for(int i = 0;i<d;i++)
            {
                int prevProfit = dp[t-1][i];
                int todayProfit = A[d] - A[i];
                maxPrevTransaction = max(maxPrevTransaction,prevProfit + todayProfit);
            }
            dp[t][d] = max(dp[t][d-1],maxPrevTransaction);
        }
    }
    
    return dp[B][n-1];
    
}
