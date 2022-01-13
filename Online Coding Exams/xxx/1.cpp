//binary tree

// edges are not strong (can break anytime)
// node can break and take away chil
// P(E) = k*distanceFromRoot


// 1. 1 node breaks away

// Expected no(MEAN) of nodes left in tree

// eg.                     5(7) 
//               3(3)                6(3)              ---->  1
//         4,1        7,1      8,1       9,1          ---->  2
        
        
//         4(2k) + 2(k) = 1
//         k = 0.1
        
        
//         E(x) = sum (p(breaking) * nodes_left)
        
//         4*0.1 + 0.1*4      ---> 0.8
//         6*0.2 ... 4         --> 4.8
        
//         (5.6)
        
//     NOTE
//     1. can be skwewd



/*

            root ---> (left + right +1)
    left            right
*/

struct node
{
    int val;
    int count;
    node* left,*right;
    node(int data):val(data),left(nullptr),right(nullptr),count(1){}
};
/*
    3 6    --> 2
      4 7  8 9                               n       divForK
                                             7         0 ---> 2*1 --> 4*2
*/
int calculateChildren(node *root)
{
    //leaf
    if(!root->left && !root->right)
        root->count = 1;
    
    //left first
    calculateChildren(root->left);
    calculateChildren(root->right);
    
    root->count = root->left->count + root->right->count + 1;
}
int calculateExpected(node *root)
{
    if(!root)
        return 0;
    
    //level order
    queue<node*> Q;
    Q.push(root);
    int n = 0;
    int level = 0;
    int divForK = 0;
    while(!Q.empty())
    {
        int size = Q.size();
        if(level > 0)           
            divForK += level*size;
        
        for(int i = 0;i<size;i++)
        {
            node* temp = Q.front(); Q.pop();
            n++;
            
            if(temp->left)
                Q.push(temp->left);
            if(temp->right)
                Q.push(temp->right);
        }
        
        level++;
    }
}