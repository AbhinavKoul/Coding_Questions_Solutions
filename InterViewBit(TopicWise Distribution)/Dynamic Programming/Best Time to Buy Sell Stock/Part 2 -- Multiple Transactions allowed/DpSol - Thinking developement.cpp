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
/*
Dp[i] --> max profit if you buy at i...n (sell at n)

now at any currrent position, you can either buy there or not.

1) if you buy
    --> dp[i] = max(dp[j] + (A[j] - A[i])) for all j > i --and-- if this is not good enough, then we dont buy dp[i+1]
2) dont buy
    --> dp[i] = dp[i+1]
    
*/
int maxProfit(const vector<int> &A) {
    int n = A.size();
    if(n == 0)
        return 0;
    v<int> dp(n,0);
    
    dp[n-1] = 0;
    
    //
    for(int i = n-2;i>=0;i--)
    {
        dp[i] = dp[i+1];
        for(int j = i+1;j<n;j++)
        {
            dp[i] = max(dp[i],dp[j] + (A[j] - A[i]));
        }
    }
    
    return dp[0];

}