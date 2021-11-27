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

// Brute Force --> Backtracking recursion!!
bool isSubsetHelper(const v<int> &arr, int i,int sum)
{
    //base
    if(sum == 0)
        return true;
        
    if(i >= arr.size())
        return false;
    
    if(arr[i] > sum)
        return isSubsetHelper(arr,i+1,sum);
    
    return isSubsetHelper(arr,i+1,sum) || isSubsetHelper(arr,i+1,sum - arr[i]);
}
int solve(vector<int> &A, int B) {
    
    return isSubsetHelper(A,0,B);
    
}

// Generally we think top bottom, from bigger set to smaller, not like one by one as i did

bool isSubsetSum(int set[], int n, int sum)
{
   
    // Base Cases
    if (sum == 0)
        return true;
    if (n == 0)
        return false;
 
    // If last element is greater than sum,
    // then ignore it
    if (set[n - 1] > sum)
        return isSubsetSum(set, n - 1, sum);
 
    /* else, check if sum can be obtained by any
of the following:
      (a) including the last element
      (b) excluding the last element   */
    return isSubsetSum(set, n - 1, sum)
           || isSubsetSum(set, n - 1, sum - set[n - 1]);
}
 
// Driver code
int main()
{
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    if (isSubsetSum(set, n, sum) == true)   //top down!
         cout <<"Found a subset with given sum";
    else
        cout <<"No subset with given sum";
    return 0;
}


// --------------------------------------MEMORIXZATION ON MINE RECURSION -------------------------------------
int isSubsetHelper(const v<int> &arr, int i,int sum,v<v<int>> &dp)
{
    //base
    if(dp[i][sum] != -1)
        return dp[i][sum];
        
    if(sum == 0)
        return dp[i][sum] = 1;
        
    if(i >= arr.size())
        return dp[i][sum] = 0;
    
    if(arr[i] > sum)
        return dp[i][sum] = isSubsetHelper(arr,i+1,sum,dp);
    
    return dp[i][sum] = isSubsetHelper(arr,i+1,sum,dp) || isSubsetHelper(arr,i+1,sum - arr[i],dp);
}
int solve(vector<int> &A, int B) {
    v<v<int>> dp(A.size() + 1,v<int>(B+1,-1));
    return isSubsetHelper(A,0,B,dp);
    
}