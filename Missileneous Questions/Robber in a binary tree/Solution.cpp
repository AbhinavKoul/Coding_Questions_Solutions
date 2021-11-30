#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*
All the time i was thinking of passing parameters so as to send before and after, but if you wanna do that in bottom up fashion as done here,just pass as return values!

*/
class Solution {
public:
    /* return {a,b} pair means
            a -> max robbery when stealing at node
            b ->max amt when you dont steal at node
    */
    pair<int,int> helper(TreeNode* root)
    {
        if(!root)
            return {0,0};
        
        pair<int,int> left = helper(root->left);
        pair<int,int> right = helper(root->right);
        
        //steal here
        int stealNode = left.second + right.second + root->val;
        //dont steal here
        
        // remember this doent mean that you need to steal at next level compulsory--> there may be a situation where you can skip next level as well to get the max amount
        int leaveNode = max(left.first,left.second) + max(right.first,right.second);
        
        return {stealNode,leaveNode};
       
        
    }
    int rob(TreeNode* root) {
        pair<int,int> ans = helper(root);
        
        return max(ans.first,ans.second);
    }
};