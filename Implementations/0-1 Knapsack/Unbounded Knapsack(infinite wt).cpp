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

#define mod 1000007
// https://www.geeksforgeeks.org/coin-change-dp-7/
// https://www.interviewbit.com/old/problems/coin-sum-infinite/
int coinchange2(vector<int> &A, int B) {

    int n = A.size();

    //make it one based indexing
    A.insert(A.begin(),0);
    
    //table
    v<v<int>> dp(n+1,v<int>(B+1));    
    
    for(int i = 0;i<=n;i++)
        dp[i][0] = 1;
        
    for(int i = 1;i<=B;i++)
        dp[0][i] = 0;
        
        
    //go for each item
    for(int i = 1;i<=n;i++)
    {   //for each capacity
        for(int j = 1;j<=B;j++)
        {
            if(A[i] > j)   //no choice[current capacity cant accomodate it] --> only one option
                dp[i][j] = dp[i-1][j];
            else    //choose between should i take it or not
                dp[i][j] = (dp[i-1][j] + dp[i][j-A[i]])%mod;
        }
    }
    
    for(auto i : dp)
    {
        cout<<"\n";
        for(auto j : i)
            cout<<j<<" ";
    }
    return dp[n][B]%mod;
}
