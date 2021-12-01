#include<iostream>
#include<vector>
#include<queue>
using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
#define v vector
/*
Time --> O(N) ==> since visit all nodes once
space --> O(N) ==> QUEUE
*/
vector<int> DiagonalTraversal_LevelOrderType(TreeNode* A) {
    v<int> res;
    queue<TreeNode*> Q;
    
    Q.push(A);
    
    while(!Q.empty())
    {
        // Travel current diagonal level
        for(int i = 0;i<Q.size();i++)
        {
            TreeNode* root = Q.front(); Q.pop();
            
            //go the entire right path
            while(root)
            {
                if(root->left)
                    Q.push(root->left); // --> increment level and inseert to queue
                
                res.push_back(root->val);
                
                root = root->right;
            }
        }
    }
    
    return res;
}