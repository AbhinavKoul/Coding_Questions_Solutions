// Link : https://leetcode.com/problems/jump-game-ii/
#include<iostream>
#include<vector>

class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1)  // only 1 element just return it off
            return 0;
        
        int count = 0;  //keep count of steps
        
        int i = 0;
        while(i<n)
        {
            int range = nums[i] + i;    //range it can travel in future
            if(range >= n-1)
                break;
            
            // to calculate the best element greedily which leads to the maximum range
            int temp = INT_MIN;
            int temp_ind;
            
            for(int j = i;j<range;j++)
            {
                i++;
                if(temp < i + nums[i])
                {
                    temp = i + nums[i];
                    temp_ind = i;
                }
            }
            //increment the count of jump
            count++;
            i = temp_ind;
        }
        count++;
        return count;
    }
};