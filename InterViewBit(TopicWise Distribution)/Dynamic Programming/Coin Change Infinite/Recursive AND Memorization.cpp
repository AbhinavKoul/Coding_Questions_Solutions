#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
#define um unordered_map
#define mod 1000000007
#define ll long long int
using namespace std;
#define v vector
//------------------------------------------------------ RECURSIVE ----------------------------------------------//
int helper(const v<int> &arr,int idx,int sum)
{
    // cout<<"\n"<<arr[i]<<" : "<<sum;
    //base
    if(sum == 0)
        return 1;
        
    if(idx>=arr.size())
        return 0;
        
    int cnt = 0;
    //normal
    for(int i = idx;i<arr.size();i++)   //so that repetition doesnt happen
    {
        if(sum >= arr[i])
            cnt += helper(arr,i,sum - arr[i]);

    }
    
    return cnt;
}

int coinchange2(vector<int> &A, int B) {

    int n = A.size();
    int cnt = 0;
    
    for(int i = 0;i<n;i++)
    {
        if(B >= A[i])
            cnt += helper(A,i,B - A[i]);
    }
    
    return cnt;
}


// ------------------------------------------------ top down MEMORIZATION --------------------------------------------------- //
#define v vector
#define mod 1000007
int helper(const v<int> &arr,int idx,int sum,v<v<int>> &dp)
{
    // cout<<"\n"<<arr[i]<<" : "<<sum;
    if(dp[idx][sum] != -1)
        return dp[idx][sum];
        
    //base
    if(sum == 0)
        return dp[idx][sum] = 1;
        
    if(idx>=arr.size())
        return dp[idx][sum] = 0;
        
    int cnt = 0;
    //normal
    for(int i = idx;i<arr.size();i++)
    {
        if(sum >= arr[i])
            cnt = (cnt + helper(arr,i,sum - arr[i],dp))%mod;

    }
    
    return dp[idx][sum] = cnt%mod;
}

int coinchange2(vector<int> &A, int B) {

    int n = A.size();
    int cnt = 0;
    v<v<int>> dp(n+1,v<int>(B+1,-1));
    
    for(int i = 0;i<n;i++)
    {
        if(B >= A[i])
            cnt = (cnt + helper(A,i,B - A[i],dp))%mod;
    }
    
    return cnt%mod;
}
