#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
#define v vector
#define um unordered_map
#define mod 1000000007
#define ll long long int
using namespace std;
// https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/603072/C%2B%2B-solution-O(n)-with-detailed-explanation


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int helper(TreeNode* root, int &result)
{
    if(!root)
        return 0;
        
    //postorder(LRN)
    // check entire left subtree and then right --> then only you can choose at the end to select node or not
    
    int leftPath = helper(root->left,result);
    int rightPath = helper(root->right,result);
    
    int value = max(leftPath + rightPath + root->val,root->val);    //will handle negative as well
    result = max(result,value);
    
    return max(max(leftPath,rightPath) + root->val,root->val);  // to handle negative
}

//---------------------------------------------------- more readable way to handle negativges ------------------------------------
int helper(TreeNode* root, int &result)
{
    if(!root)
        return 0;
        
    //postorder(LRN)
    // check entire left subtree and then right --> then only you can choose at the end to select node or not
    
    int leftPath = max(helper(root->left,result),0);    //eliminated negatives here only
    int rightPath = max(helper(root->right,result),0);
    
    int value = leftPath + rightPath + root->val;    
    result = max(result,value);
    
    return max(leftPath,rightPath) + root->val;  
}

int maxPathSum(TreeNode* A) {
   int maxSum = INT_MIN;
   
   helper(A,maxSum);
   
   return maxSum;
}
