#include<iostream>
// #include<bits/stdc++.h>
#include<vector>
using namespace std;

#define v vector

int firstMissingPositive(vector<int>& nums) {
        if(nums.size() == 0)
            return 1;
        v<bool> is_present(nums.size()+1);
        
        for(auto i: nums)
        {
            if(i<=0)
                continue;
            else if(i>is_present.size())
                continue;
            else
            {
                is_present[i] = true;
            }
        }
        
        v<bool>::iterator itr = find(is_present.begin()+1,is_present.end(),false);
        
        if(itr == is_present.end())
            return is_present.size();
        else
            return(abs(distance(itr,is_present.begin())));
        
        
}