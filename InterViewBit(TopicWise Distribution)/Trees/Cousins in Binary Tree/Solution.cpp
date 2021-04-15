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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> solve(TreeNode* A, int B) 
{   
    //if root only has value, thus wont have any cousins
    if(A->val==B)
        return {};
    
    //cousins for the level where value is found
    vector<int> res;
    queue<TreeNode *>Q;
    
    //Level Order Traversal
    Q.push(A);
    bool found=false;
    while(!Q.empty())
    {
        int n = Q.size(); // so we know current parents count, which will be used to find all the cousins
        
        // to keep track of current cousins
        vector<int>tmp;     //could have used normal queue pair but then pushing all elements in vecor is a bit complicated
        
        for(int i = 0; i<n ;i++)    //traverse till all the parents are removed and all cousins accounted for
        {
            TreeNode *node=Q.front(); Q.pop();
            
            //if target is a value of one of the child of parent
            if((node->left && node->left->val==B) || (node->right && node->right->val==B))
                found=true;
            else
            {
                if(node->left)
                {
                    tmp.push_back(node->left->val);
                    Q.push(node->left);
                }
                if(node->right)
                {
                    tmp.push_back(node->right->val);
                    Q.push(node->right);
                }
            }
        }
        
        if(found)
        {
            res = tmp;
            break;
        }
    }
    return res;
}

