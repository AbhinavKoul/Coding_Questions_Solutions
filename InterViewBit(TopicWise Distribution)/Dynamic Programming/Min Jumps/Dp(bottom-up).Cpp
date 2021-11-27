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
here dp[i] --> min jumps to reach that point from start

        now to check dp[i], we need to check for all 0...i before it to see which one is min
*/

#define v vector
int jump(vector<int> &arr) 
{
    int n = arr.size();

    v<int> dp(n,INT_MAX);
    
    dp[0] = 0;
    
    //calculating min jump for ith index till n-1
    for(int i = 1;i<n;i++)
    {
        //now check for all elements that come before this
        for(int j = 0;j<i;j++)
        {
            //if rachable from that start point
            if(j + arr[j] >= i && dp[j] != INT_MAX)
                dp[i] = min(dp[i],dp[j] + 1);
        }
    }
    
    if(dp[n-1] == INT_MAX)
        return -1;
    
    return dp[n-1];
}  
