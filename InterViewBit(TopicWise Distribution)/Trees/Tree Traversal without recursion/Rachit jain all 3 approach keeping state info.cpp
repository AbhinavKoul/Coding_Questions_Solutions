#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct Node {
      int val;
      Node *left;
      Node *right;
      Node(int x) : val(x), left(NULL), right(NULL) {}
  };

void printPostorder(struct Node* A)
{
    stack<pair<Node*,int>>st;
    st.push({A,0});

    while(!st.empty())
    {
        auto p = st.top();
        auto node = p.first;
        auto state= p.second;
        st.pop();


        if(node==NULL || state==3)
            continue;

        st.push({node,state+1});

        if(state==1)
            st.push({node->right,0});
        else if(state==0)
            st.push({node->left,0});
        else if(state==2)
            cout<<node->val<<" ";
    }
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct Node* A)
{
    stack<pair<Node*,int>>st;
    st.push({A,0});
    
    while(!st.empty())
    {
        auto p = st.top();
        auto node = p.first;
        auto state= p.second;
        st.pop();

        if(node==NULL || state==3)
            continue;

        st.push({node,state+1});

        if(state==2)
            st.push({node->right,0});
        else if(state==0)
            st.push({node->left,0});
        else if(state==1)
            cout<<node->val<<" ";
    }
}

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct Node* A)
{
    stack<pair<Node*,int>>st;
    st.push({A,0});

    while(!st.empty())
    {
        auto p = st.top();
        auto node = p.first;
        auto state= p.second;
        st.pop();

        if(node==NULL || state==3)
            continue;

        st.push({node,state+1});

        if(state==2)
            st.push({node->right,0});
        else if(state==1)
            st.push({node->left,0});
        else if(state==0)
            cout<<node->val<<" ";

    }
}