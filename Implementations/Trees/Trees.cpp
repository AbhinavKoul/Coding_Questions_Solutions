#include<iostream>
// #include<bits/stdc++.h>
#include<vector>
#include<queue>

#define v vector
using namespace std;

struct node
{
    int data;
    node *left,*right;
    node(int val) : data(val),left(nullptr),right(nullptr) { }
};

v<int> Inorder(node * head,v<int>& res)
{
    if(head!=nullptr)
    {
        Inorder(head->left,res);
        res.push_back(head->data);
        Inorder(head->right,res);

        return res;
    }

}

v<int> LevelOrderTransvsal_helper(node * head,v<int>& res,queue<node*>& Q)
{
    Q.push(head);

    while (!Q.empty())
    {
        node* src = Q.front();
        res.push_back(src->data);
        Q.pop();

        if(src->left!=nullptr)
            Q.push(src->left);
        if(src->right!=nullptr)
            Q.push(src->right);

    }

    return res;
    
}

void LevelOrderTransvesal(node*head)
{
    queue<node*> Q;
    v<int> res;
    res = LevelOrderTransvsal_helper(head,res,Q);

    for(auto i: res)
        cout<<i<<" ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    node* root = new node(1);
    root->left = new node(2);
    root->right =new node(3);

    root->left->left = new node(4);
    root->right->left = new node(5);

    
    // v<int> res;
    // res = Inorder(root,res);

    cout<<" fdsfdsds : \n";
    LevelOrderTransvesal(root);

    // for(auto i : res)
    //     cout<<i<<" ";

    return 0;
}
