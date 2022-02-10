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

class Solution {
public:
    /*
    O(N) time
    O(1) space
    */
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder; 
        
        TreeNode* cur = root; 

        while(cur != NULL) 
        {
            // if no left, then print and goto right
            if(cur->left == NULL)   
            {
                inorder.push_back(cur->val); 
                cur = cur->right; 
            }
            else 
            {
                //find rightmost in left subtree
                TreeNode* prev = cur->left; 
                while(prev->right != NULL && prev->right != cur)    //2nd condition will come true when you have threaded connection
                    prev = prev->right; 
                
                if(prev->right == NULL)     //no connection to cur
                {
                    //establish connection to cur
                    prev->right = cur;
                    cur = cur->left;    //<-- since left tree has made connection, we need to go and solve the left tree
                }
                else 
                {
                    //remove connection from cur
                    prev->right = NULL; 
                    inorder.push_back(cur->val);    //push   
                    cur = cur->right;               //goto right now, as left tree is already been solved
                }
            }
        }
        return inorder; 
    }
};