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
#define v vector
#define v vector
int knapHelper(const v<int> &val,const v<int> &wt,int i,int j,v<v<int>> &dp)
{
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    //base case
    if(i <= 0 || j <= 0)
        return 0;
        
    //normal
    if(j < wt[i-1]) // --> no option as current capacity cant take the elemwent inside
        return (dp[i][j] = knapHelper(val,wt,i-1,j,dp));
    
    //--> check for both options ie. taking and leaving this argument
    return(dp[i][j] = max(knapHelper(val,wt,i-1,j,dp),val[i] + knapHelper(val,wt,i-1,j-wt[i],dp)));
    
}
int solve(vector<int> &A, vector<int> &B, int C) {

    int n = A.size();

    //make it one based indexing to make manipulations readable!!
    A.insert(A.begin(),0);
    B.insert(B.begin(),0);
    
    v<v<int>> dp(n+1,v<int>(C+1,-1));    
    return knapHelper(A,B,n,C,dp);
}

