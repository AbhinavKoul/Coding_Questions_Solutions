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

/*
LEVEL ORDER TRAVERSAL, WITH KEEPING TRACK OF SPECIFIC LEVEL SO THAT WHEN YOU FIND ANY LEAF NODE, RETURN!!!
*/
int minDepth(TreeNode* root) 
{
    if (root == NULL) return 0;
    
    queue<TreeNode*> Q;
    Q.push(root);
    int level = 0;
    
    while (!Q.empty()) 
    {
        int k = Q.size();
        
        for (int j=0; j<k; j++) 
        {
            TreeNode* rt = Q.front();

            if (rt->left) 
                Q.push(rt->left);
            if (rt->right) 
                Q.push(rt->right);
            
            Q.pop();
            
            //leaf node
            if (!rt->left && !rt->right) 
                return level;
        }

        level++;
    }

    return -1; //For the compiler thing. The code never runs here.
}