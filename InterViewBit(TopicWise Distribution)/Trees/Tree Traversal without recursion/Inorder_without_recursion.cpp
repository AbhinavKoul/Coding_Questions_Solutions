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

void inOrder(TreeNode *A, vector<int> &res){
    
    stack<TreeNode *>s;
    if(A == nullptr) 
        return;

    TreeNode *curr = A->left;
    s.push(A);
    
    while(!s.empty() || curr)
    {
        while(curr != nullptr)  //keep going left till the maximum left
        {
            s.push(curr);
            curr = curr->left;
        }
        //leftest node enter in result
        TreeNode *temp = s.top();   
        res.push_back(temp->val);
        s.pop();
        
        // now goto right subtree
        curr = temp->right;
    }

} 

vector<int> inorderTraversal(TreeNode* A) {
    vector<int> res;
    inOrder(A, res);
    return res;
}