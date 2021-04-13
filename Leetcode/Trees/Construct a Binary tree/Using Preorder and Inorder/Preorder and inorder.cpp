#include<iostream>
// #include<bits/stdc++.h>
#include<vector>
#include<queue>

#define v vector
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int n;
    
    TreeNode* helper(v<int> &preorder,v<int> &inorder,int &preorder_index,int inorder_begin, int inorder_end)
    {
        //if out of bound pointers
        if(preorder_index >= preorder.size() || inorder_begin > inorder_end)
            return nullptr;
        
        TreeNode* head = new TreeNode(preorder[preorder_index]);
    
        int pos = find(inorder.begin() + inorder_begin, inorder.begin() + inorder_end + 1,preorder[preorder_index]) - inorder.begin();
        // position of element in inorder array, where we will further divide it into 2 parts from
        
        preorder_index++;       //we take this var as reference as otherwise we will keep finding same thing again and again!!
        
        head->left = helper(preorder,inorder,preorder_index,inorder_begin,pos - 1);
        head->right = helper(preorder,inorder,preorder_index,pos + 1,inorder_end);
        
        return head;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n = inorder.size();
        int preorder_index = 0;
        return helper(preorder,inorder,preorder_index,0,n-1);
        
    }
};