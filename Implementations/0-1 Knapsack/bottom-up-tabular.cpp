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
int solve(vector<int> &val, vector<int> &wt, int C) {

    int n = val.size();

    //make it one based indexing
    val.insert(val.begin(),0);
    wt.insert(wt.begin(),0);
    
    //table
    v<v<int>> dp(n+1,v<int>(C+1));    
    
    for(int i = 0;i<=n;i++)
        dp[i][0] = 0;
        
    for(int i = 0;i<=C;i++)
        dp[0][i] = 0;
        
        
    //go for each item
    for(int i = 1;i<=n;i++)
    {   //for each capacity
        for(int j = 1;j<=C;j++)
        {
            if(j < wt[i])   //no choice[current capacity cant accomodate it] --> only one option
                dp[i][j] = dp[i-1][j];
            else    //choose between should i take it or not
                dp[i][j] = max(dp[i-1][j], val[i] + dp[i-1][j-wt[i]]);
        }
    }
    
    return dp[n][C];
}
