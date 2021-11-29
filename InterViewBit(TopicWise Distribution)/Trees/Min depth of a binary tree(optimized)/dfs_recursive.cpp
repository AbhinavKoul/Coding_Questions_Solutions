class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        
        if(min(left,right) == 0)
            return max(left,right) + 1;
        
        return min(left,right) + 1;
    }
};