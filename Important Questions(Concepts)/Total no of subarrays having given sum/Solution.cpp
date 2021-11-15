#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        
        int  n = nums.size();
        int sum = 0;
        int count = 0;
        um[0] = 1;
        for(int i = 0;i<n;i++)
        {
            sum += nums[i];
            if(um.find(sum-k)!=um.end())
                count+= um[sum-k];
            
            um[sum]++;
        }
        
        return count;
        
    }
};