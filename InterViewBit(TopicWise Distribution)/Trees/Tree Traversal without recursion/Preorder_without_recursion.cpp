#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  
#define v vector
void preorder(TreeNode* A,v<int> &res)
{
    stack<TreeNode*> s;
    s.push(A);
    
    while(!s.empty())
    {
        TreeNode* temp = s.top(); s.pop();
        res.push_back(temp->val);
        
        //we need to process left 1st, so that must be at top of stack
        // thus we insert right 1st in stakck
        if(temp->right !=nullptr)
            s.push(temp->right);
        if(temp->left != nullptr)
            s.push(temp->left);
    }
}
vector<int> preorderTraversal(TreeNode* A) {
    v<int> res;
    preorder(A,res);
    return res;
}