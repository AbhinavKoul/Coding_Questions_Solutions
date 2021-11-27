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

//similar to knapsack
int solve(vector<int> &A, int B) {
    int n = A.size();
    v<v<int>> dp(n + 1,v<int>(B+1));
    
    //1 based indexing
    A.insert(A.begin(),0);
    //base
    dp[0][0] = 1;
    for(int i = 1;i<=n;i++)
        dp[i][0] = 1;
    
    for(int i = 1;i<=B;i++)
        dp[0][i] = 0;
    
    //normal
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=B;j++)
        {
            if(j < A[i])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-A[i]]);
        }
    }
    
    return dp[n][B];
}
