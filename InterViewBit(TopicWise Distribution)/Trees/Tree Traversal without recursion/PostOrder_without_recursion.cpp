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
vector<int> postorderTraversal(TreeNode* A) {
    stack<TreeNode*> s;
    s.push(A);
    v<int> res;
    while(!s.empty())
    {
        TreeNode * temp = s.top();s.pop();
        res.push_back(temp->val);
        
        if(temp->left)
            s.push(temp->left);
        if(temp->right)
            s.push(temp->right);
    }
    
    reverse(res.begin(),res.end());
    return res;
}