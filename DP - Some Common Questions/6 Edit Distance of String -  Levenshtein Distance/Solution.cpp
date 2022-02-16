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
//https://www.youtube.com/watch?v=MiqoA-yF-0M
using namespace std;
//https://www.interviewbit.com/problems/edit-distance/
#define v vector

// top-down recursive code (O(3^N))
int recHelper(int i, int j, const string&A, const string &B)
{
    //base
    if(i==0)    //1st string empty
        return j;
        
    if(j == 0) //2nd string empty
        return i;
        
    //same char
    if(A[i-1] == B[j-1])
        return recHelper(i-1,j-1,A,B);
        
    //options
    int insert = recHelper(i,j-1,A,B);
    int del = recHelper(i-1,j,A,B);
    int replace = recHelper(i-1,j-1,A,B);
    
    return 1 + min(insert,min(del,replace));    
}
int minDistance(string A, string B) {
    return recHelper(A.size(),B.size(),A,B);
}

// DP BASED --> Bottom-UP
int minDistance_BottomUp(string A, string B) {

    v<v<int>> dp(A.size() + 1,v<int>(B.size() + 1));
    
    int n = A.size();
    int m = B.size();
    
    dp[0][0] = 0;
    for(int i = 1;i<=n;i++)
    {
        dp[i][0] = i;
    }
    
    for(int j = 1;j<=m;j++)
        dp[0][j] = j;
        
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            if(A[i-1] == B[j-1])    //if last characters are same
                dp[i][j] = dp[i-1][j-1];
            else
            {
                dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1; //measure all the options
            }
        }
    }
    
    return dp[n][m];
}
//DP --> SPACE EFFECTIVE (only 2 O(N) vectors)
int minDistance(string word1, string word2) 
{
        int m = word1.size(), n = word2.size();
        vector<int> pre(n + 1, 0), cur(n + 1, 0);

        for (int j = 1; j <= n; j++) 
            pre[j] = j;

        for (int i = 1; i <= m; i++) 
        {
            cur[0] = i;
            for (int j = 1; j <= n; j++) 
            {
                if (word1[i - 1] == word2[j - 1]) 
                    cur[j] = pre[j - 1];
                else 
                    cur[j] = min(pre[j - 1], min(cur[j - 1], pre[j])) + 1;
                
            }

            fill(pre.begin(), pre.end(), 0);
            swap(pre, cur);
        }
        
        return pre[n];
    }

