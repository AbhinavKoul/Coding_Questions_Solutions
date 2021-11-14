#include<iostream>
#include<vector>
using namespace std;
/*
Time : O(N)
Space: O(1)
*/
int firstMissingPositive(vector<int> &ar) {
    int n=ar.size();
    for(int i=0;i<n;i++)
        if(ar[i]<1)
            ar[i]=n+1;
            
    for(int i=0;i<n;i++)
        if(abs(ar[i]-1)<n)
            ar[abs(ar[i])-1]*=-1;
    
    for(int i=0;i<n;i++)
        if(ar[i]>0)
            return i+1;
    
    return n+1;
}
//---------------------- more robust ------------------------
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0;i<n;i++)
        {
            if(nums[i] < 1)
                nums[i] = n+1;
        }
        
        for(int i = 0;i<n;i++)
        {
            int k = abs(nums[i]);
            
            if(k>n)
                continue;
            
            nums[k-1] = nums[k-1] > 0?nums[k-1]*-1:nums[k-1];
            
        }
        
        for(int i = 0;i<n;i++)
        {
            
            if(nums[i]>0)
                return i+1;
        }
            
        
        return n+1;
    }
};
