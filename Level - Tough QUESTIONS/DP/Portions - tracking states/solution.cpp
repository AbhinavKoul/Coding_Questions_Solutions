
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define v vector
//https://www.interviewbit.com/old/problems/potions/

#define v vector
int mod = 1e9 + 7;
int Solution::minSmoke(vector<int> &A) {
    int n = A.size();
    v<int> prefixSum(n);
    prefixSum[0] = A[0];
    for(int i = 1;i<n;i++)
        prefixSum[i] = prefixSum[i-1] + A[i];
    v<v<int>> dp(n,v<int>(n));
    
    for(int g = 0;g<n;g++)
    {
        for(int i = 0,j = g;j<n;i++,j++)
        {
            if(g == 0)
                dp[i][j] = 0;
            else
            {
                int res = INT_MAX;
                
                for(int k = i;k<j;k++)
                {
                    int left=  (prefixSum[k] - prefixSum[i] + A[i])%100;
                    int right = (prefixSum[j] - prefixSum[k])%100;
                    if(k == i && A[i] == 100)
                        left = 100;
                    
                    if(k == j-1 && A[j] == 100)
                        right = 100;
                        
                    res = min(res,(dp[i][k] + dp[k+1][j] + (left*right))%mod);
                    
                    dp[i][j] = res;
                }
            }
        }
    }
    
    return dp[0][n-1];
}