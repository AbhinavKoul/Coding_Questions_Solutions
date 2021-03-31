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

TreeNode* invertTree(TreeNode* A) {
    if(A == nullptr)
        return nullptr;
        
    TreeNode* temp;
    temp = A->left;
    A->left = A->right;
    A->right = temp;
    
    invertTree(A->left);
    invertTree(A->right);
    
    return A;
}
