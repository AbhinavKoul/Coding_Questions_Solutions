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
struct TreeNode
{
    int val;
    TreeNode *left,*right;
    TreeNode(int val) : val(val),left(nullptr),right(nullptr) { }
};

vector<int> preorderTraversal(TreeNode* root) {
        v<int> preorder;
        
        TreeNode *cur = root;
        
        while(cur)
        {
            if(!cur->left)
            {
                preorder.push_back(cur->val);
                cur = cur->right;
                continue;
            }
            
            //find rightmost in left subtree
            TreeNode *prev = cur->left;
            while(prev->right && prev->right != cur)
                prev = prev->right;
            
            if(prev->right == nullptr)
            {
                prev->right = cur;
                preorder.push_back(cur->val);
                cur = cur->left;
            }
            else
            {
                prev->right = nullptr;
                cur = cur->right;
            }
        }
        
        return preorder;
    }