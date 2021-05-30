#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define v vector
//LINK : https://binarysearch.com/room/Empty-string-iiszPSAuPK?questionsetIndex=2

// int solve(vector<int>& nums, int k) {
//     sort(nums.begin(),nums.end());
//     return nums[k];
// }
// int solve(vector<int>& nums, int k) {
//     nth_element(nums.begin(), nums.begin() + k, nums.end());
//     return nums[k];
// }


int partition(vector<int>& nums, int start, int end) {
    int pivot = nums[start], j = end;
    for (int i = start + 1; i <= j;) {
        if (nums[i] >= pivot)
            swap(nums[i], nums[j--]);
        else
            i++;
    }
    swap(nums[start], nums[j]);
    return j;
}

int solve(vector<int>& nums, int k) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int m = partition(nums, l, r);
        if (m == k)
            return nums[m];
        else if (m < k)
            l = m + 1;
        else
            r = m - 1;
    }
    return nums[l];
}