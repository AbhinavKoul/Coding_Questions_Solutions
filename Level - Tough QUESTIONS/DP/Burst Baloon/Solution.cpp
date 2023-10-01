#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define v vector
//https://www.youtube.com/watch?v=Yz4LlDSlkns&ab_channel=takeUforward

#define v vector
int mod = 1e9 + 7;

#define v vector
//recursive code
class Solution {
public:
    int recHelper(int l, int r, v<int>& nums)
    {
        //base
        if(l > r)
            return 0;

        int maxi = INT_MIN;

        for(int i = l;i<=r;i++)
        {
            int val = (nums[l-1]*nums[i]*nums[r+1]) + recHelper(i+1,r,nums) + recHelper(l,i-1,nums);
            maxi = max(maxi,val);
        }

        return maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);

        return recHelper(1,n,nums);
    }
};

//tabular bottom up
//convert the recursive one in oppossite way
// in recursive we were going i = 1->n ==> tabular n->1 and similarly for col.
int maxCoins(vector<int>& nums) {
    int n = nums.size();
    nums.insert(nums.begin(),1);
    nums.push_back(1);
    v<v<int>> dp(n+2,v<int>(n+2,0));
    
    for(int left = n; left>=1;left--)
    {
        for(int right = 1;right<=n;right++)
        {
            if(left > right)
                continue;

            int maxi = INT_MIN;
            for(int i = left;i<=right;i++)
            {
                int cost = nums[i]*nums[left-1]*nums[right+1] + dp[i+1][right] + dp[left][i-1];
                maxi = max(maxi,cost);
            }

            dp[left][right] = maxi;
        }
    }

    return dp[1][n];
}