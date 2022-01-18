#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

#define v vector
class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        v<int> arr;
        arr.push_back(0);
        
        for(int i = 0;i<n;i++)
            arr.push_back(price[i]);
        
        //dp[i] --> max value till i lenght of rod
        v<int> dp(arr.size());
        dp[0] = 0;
        dp[1] = arr[1];
        
        for(int i = 2;i<arr.size();i++)
        {
            int maxi = INT_MIN;
            int left = 0;
            int right = i;
            dp[i] = arr[i];
            while(left<=right)
            {
                int val = dp[left] + dp[right];
                maxi = max(maxi,val);
                left++;
                right--;
            }
            
            dp[i] = maxi;
        }
        
        // for(auto i : dp)
        //     cout<<i<<" ";
        
        return dp[arr.size() - 1];
    }
};