class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int l= nums.size(),i,j;
        set<vector<int>> fin;
        vector<int>demo;
        map<int,int> dict;
        for (i=0;i<l;i++){
            int sum= 0-nums[i];
            for (j=i+1;j<l;j++){
                int target=sum-nums[j];
                if (dict.find(target) == dict.end()){
                    dict[nums[j]]=j;
                }
                else{
                    auto itr=dict.find(target);
                    demo.push_back(nums[i]);
                    demo.push_back(nums[j]);
                    demo.push_back(nums[itr->second]);
                    sort(demo.begin(),demo.begin()+3);
                    fin.insert(demo);
                    demo.clear();
                }
            }
            dict.clear();
        }
        vector<vector<int>> ans(fin.begin(),fin.end());
        return ans;
    }
};