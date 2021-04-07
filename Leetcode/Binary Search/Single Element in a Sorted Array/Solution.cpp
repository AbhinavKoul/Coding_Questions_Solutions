#include<iostream>
// #include<bits/stdc++.h>
#include<vector>
#include<queue>

#define v vector
using namespace std;

class Solution {
public:
    #define v vector
    int n;
    bool check(int mid,const v<int> &nums)
    {
        /*
        To make sure mid stays within its boundaries
        */
        if(mid > 0 && mid <n)
            return (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]);
        else if(mid == 0)
            return nums[mid] != nums[mid + 1];
        else
            return nums[mid] != nums[mid - 1];
    }
    
    int singleNonDuplicate(vector<int>& nums) {
        
        n = nums.size();
        if(n==1)
            return nums[0];
        int low = 0, high = nums.size() -1;
        
        while(low<=high)
        {
            int mid = (low + high)/2;
            
            if(check(mid,nums)) //check if mid is the element we were looking for?
                return nums[mid];
            
            
            //check if mid is an even or odd position
            if(mid%2 == 0)  //even index
            {
                //if equal to one less index, that means left subarray has odd elements                    ------------- same element on side where (mid) is written ---------
                // eg. [1 1 2 3 3 4 4 8 8]              [1 1 2 2 3 3 4 8 8]
                //      0 1 2 3 4 5 6 7 8                0 1 2 3 4 5 6 7 8
                //         (mid)|                                |(mid)
                //      odd side                                  odd side
                if(nums[mid - 1] == nums[mid])
                    high = mid;
                else
                    low = mid + 1;
            }
            else
            {
                // if mid is odd index and whichever side you have same, other side of that has odd numbers
                // eg. [1 1 2 3 3 4 4]           [1 1 2 2 3 4 4]
                //      0 1 2 3 4 5 6             0 1 2 3 4 5 6
                //            |(mid)               (mid)|
                //    odd side                           odd side
                if(nums[mid - 1] == nums[mid])
                    low = mid + 1;
                else
                    high = mid;
            }
        }
        return 0;
    }
};