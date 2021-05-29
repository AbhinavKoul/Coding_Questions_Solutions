/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define v vector

int leftHeight(Tree* root)
{
    if(!root)
        return 0;
    
    return leftHeight(root->left) + 1;
}
int rightHeight(Tree* root)
{
    if(!root)
        return 0;
    
    return rightHeight(root->right) + 1;
}
int solve(Tree* root) {

    if(!root)
        return 0;
    int left = leftHeight(root); //o(logn)
    int right = rightHeight(root);//o(logn)

    if(left == right)//never executes
        return pow(2,left)-1;

    return solve(root->left)+solve(root->right)+1;//->worst()

    
}