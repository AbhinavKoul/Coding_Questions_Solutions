/**
 * @file SolutionForMultipleQuestions.cpp
 * @author Abhinav Koul
 * @brief https://leetcode.com/problems/subsets/discuss/27281/A-general-approach-to-backtracking-questions-in-Java-(Subsets-Permutations-Combination-Sum-Palindrome-Partitioning)
 * @version 0.1
 * @date 2021-12-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>
using namespace std;
#define v vector
/**
 * @brief this is a backtracking easily understandable code for normal tasks which
 * are already done. Will attach link for each
 * 
 */

//1.Generate all Subsets problem (https://github.com/AbhinavKoul/Coding_Questions_Solutions/blob/0a5e951e5afefa3963680d8e519f367c526ffa17/InterViewBit(TopicWise%20Distribution)/Recursion%20or%20Backtracking/Find%20all%20subsets/Solution.cpp#L34)

// a) Backtracking Approach
void backtrackingHelper(const v<int> &nums,int idx,v<int> &temp,v<v<int>> &ans,const int n)
{
    //add the temp result in answer
    ans.push_back(temp);

    //see all children of current index
    for(int i = idx;i<n;i++)
    {
        //add current element in temp result
        temp.push_back(nums[i]);
        backtrackingHelper(nums,i+1,temp,ans,n);
        //remove this one now
        temp.pop_back();
    }
}
v<v<int>> subsets(v<int> &nums)
{
    v<v<int>> ans;
    int n = nums.size();
    v<int> temp;

    backtrackingHelper(nums,0,temp,ans,n);

    return ans;    
}

// b) Binary Mapping
v<v<int>> subsets(v<int> &nums)
{
    v<v<int>> res;
    
    int n = nums.size();
    
    
    int limit = pow(2,n);
    
    for(int i = 0;i<limit;i++)
    {
        v<int> temp;
        bitset<100> bits(i);
        
        for(int i = 0;i<n;i++)
            if(bits.test(i))
                temp.push_back(nums[i]);
        
        res.push_back(temp);
    }
    
    
    return res;
    
}
//2. Generate all Permutations
void recHelper(const v<int> &nums,v<int> &temp, v<v<int>> &result)      
{
    //base
    if(temp.size() == nums.size())
    {
        result.push_back(temp);
        return;
    }
    
    for(int j = 0;j<nums.size();j++)
    {
        if(find(temp.begin(),temp.end(),nums[j]) != temp.end())
            continue;
        
        temp.push_back(nums[j]);
        recHelper(nums,temp,result);
        temp.pop_back();
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    
    v<v<int>> result;
    v<int> temp;
    
    recHelper(nums,temp,result);

    return result;
}

//3. Combinations
void recHelper(int s,v<int> &temp,int n,int k,v<v<int>> &result)
{
    //base
    if(k == 0)
    {
        result.push_back(temp);
        return;
    }
    
    //normal
    for(int i = s;i<=n;i++)
    {
        temp.push_back(i);
        recHelper(i+1,temp,n,k-1,result);
        temp.pop_back();
    }

}
vector<vector<int>> combine(int n, int k) {
    v<v<int>> result;
    v<int> temp;
    
    recHelper(1,temp,n,k,result);
    
    return result;
}

//4. Subsets with duplicates solution
void recHelper(int idx,const v<int> &nums, v<int> &temp, v<v<int>> &result)
{
    //base
    result.push_back(temp);
    
    //go for children
    for(int i = idx;i<nums.size();i++)
    {
        if(i > idx && nums[i] == nums[i-1]) //skip
            continue;
        
        temp.push_back(nums[i]);
        recHelper(i+1,nums,temp,result);
        temp.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    v<v<int>> result;
    v<int> temp;
    sort(nums.begin(),nums.end());
    recHelper(0,nums,temp,result);
    
    return result;
}

//5. Permutations with duplicates
 void recHelper(const v<int> &nums, v<bool> &recStack, v<int> &temp, v<v<int>> &result)
{
    //base
    if(temp.size() == nums.size())
    {
        result.push_back(temp);
        return;
    }
    
    for(int i = 0;i<nums.size();i++)
    {
        if(recStack[i] || (i > 0 && nums[i] == nums[i-1] && !recStack[i - 1])) //<----- Sort is needed for this!!
            continue;
        
        temp.push_back(nums[i]);
        recStack[i] = true;
        recHelper(nums,recStack,temp,result);
        temp.pop_back();
        recStack[i] = false;
        
    }
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    v<v<int>> result;
    v<int> temp;
    v<bool> recStack(nums.size(),false);
    sort(nums.begin(),nums.end());
    recHelper(nums,recStack,temp,result);
    
    return result;
}
//6. Combinations Sum - 1 (unique array)
#define v vector
class Solution {
public:
    void recHelper(const v<int> &arr,int idx,int target,v<int> &temp, v<v<int>> &result)
    {
        //base
        if(target == 0)
        {
            result.push_back(temp);
            return;
        }
        
        for(int i = idx;i<arr.size();i++)
        {
            if(arr[i] > target)
                continue;
            
            temp.push_back(arr[i]);
            recHelper(arr,i,target - arr[i],temp,result);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       v<v<int>> result;
        v<int> temp;
        
        recHelper(candidates,0,target,temp,result);
        
        return result;
    }
};
//7. Combinatiosn Sum 2 - duplicates
class Solution {
public:
    #define v vector
    void recHelper(const v<int>& arr,int idx,int target, v<int> &temp, v<v<int>> &result)
    {
        if(target == 0)
        {
            result.push_back(temp);
            return;
        }

        for(int i = idx;i<arr.size();i++)
        {
            if(arr[i] > target || i>idx && arr[i] == arr[i-1])
                continue;

            temp.push_back(arr[i]);
            recHelper(arr,i+1,target - arr[i],temp,result);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        v<v<int>> result;
        v<int> temp;
        //skip duplicates
        sort(candidates.begin(),candidates.end());
        recHelper(candidates,0,target,temp,result);
        
        return result;
    }
};