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

    TreeNode* deleteNode(TreeNode* root, int key) {
    // find the element
        
        if(!root)
            return nullptr;
        
        if(key < root->val)
            root->left = deleteNode(root->left,key);
        else if(key > root->val)
            root->right = deleteNode(root->right,key);
        else
        {
            //if leaf node
            if(!root->left && !root->right)
            {
                delete(root);
                return nullptr;
            }
            //if only one child
            if(!root->left || !root->right)
            {
                auto itr = root->left?root->left:root->right;
                delete(root);
                return itr;
            }
            //if 2 child
            if(root->left && root->right)
            {
                //finding min element in right subtree
                auto temp = root->right;
                while(temp->left)
                    temp = temp->left;
                
                //exchange the min val in right subtree with root
                root->val = temp->val;
                //update the root->right after delete that exchanged node
                root->right = deleteNode(root->right,temp->val);
            }
        }
        
        return root;
    }
};