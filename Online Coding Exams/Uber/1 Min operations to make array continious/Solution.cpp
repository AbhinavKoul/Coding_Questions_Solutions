#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;
#define v vector
//https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/
int minOperations(vector<int>& nums) 
    {
        int n = nums.size();
        
        //set for finding unique element 
        unordered_set<int> seen;
        vector<int> uniques;
        
        for(auto n : nums)
        {
            if(!seen.count(n))
                uniques.push_back(n);
            
            seen.insert(n);
        }
        
        sort(uniques.begin(),uniques.end());
        
        int ans = INT_MAX;
        for(int i = 0; i < uniques.size(); ++i) 
        {
            // Theoratical end point for the current window.
            int end = uniques[i] + n - 1;
            
            // Search for element just greater than end, where the binary search part
            // comes in.
            vector<int>::iterator upper = upper_bound(uniques.begin(), uniques.end(), end);
            
            // end + 1 = upper - unique.begin(). |len| would be end - i + 1.
            int len = upper - uniques.begin() - i;
            ans = min(ans, n - len);
        }
       return ans;
    }
