class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i,l,j;
        l=nums.size();
        for(i=0;i<l-1;i++){
            if (nums[i]>nums[i+1]){
                break;
            }
        }
        for (j=0;j<i+1;j++){
            if (target==nums[j])
                return j;
        }
        for (j=i+1;j<l;j++){
            if (target==nums[j]){
                return j;
            }
        }
        return -1;
    }
};