#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// backtraking based on apprach that you can either take this element or not
vector<vector<int>> allSubsets;
void generate(vector<int> &subset, int i, vector<int> &nums) {
        if(i == nums.size()) {
            allSubsets.push_back(subset);
            return;
        }
        
        // ith element not in the subset
        generate(subset, i+1, nums);
        
        // ith element in the subset
        subset.push_back(nums[i]);
        generate(subset, i+1, nums);
        subset.pop_back();
}

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> empty;
        generate(empty, 0 , nums);
        return allSubsets;
        
}

//my approach --> based on making a tree directly
#define v vector
class Solution {
public:
    void helper(const v<int> &nums,v<v<int>> &ans,v<int> &res,int idx, const int n)
    {
        
        if(idx > n)
            return;
        
        //put current inr res
        res.push_back(nums[idx]);
        ans.push_back(res);
        
        //see children
        for(int i = idx + 1;i<=n;i++)
        {
            helper(nums,ans,res,i,n);
        }
           
        //remove from stack
        res.pop_back();
        
        
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        v<v<int>> ans;
        ans.push_back({});
        int n = nums.size();
        v<int> res;
        
        for(int i = 0;i<n;i++)
            helper(nums,ans,res,i,n-1);
        
        return ans;
    }
};