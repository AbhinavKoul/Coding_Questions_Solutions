class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p,q,s;
        int l = nums.size();
        if (l==0){
            return 0;
        }
        int ans=1;
        q=0;
        p=1;
        while (p!=l){
            if (nums[q]==nums[p]){
               p+=1;
            }
            else{
                q+=1;
                ans+=1;
                nums[q]=nums[p];
            }
        }
        for (p=l-1;p>ans;p--){
            nums.erase(nums.begin()+p);
        }
        return ans;
    }
};