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

//O(n2) time and O(N) space
int coinchange2(vector<int> &A, int B) {

    int n = A.size();
    
    v<int> dp(B+1,0);
    
    dp[0] = 1;
    
    //iterate on denominations
    for(int i = 0;i<n;i++)
    {
        for(int j = A[i];j<=B;j++)
        {
            dp[j] += dp[j - A[i]];
        }
    }
    
    return dp[B];
}
