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


struct Node {
	int data;
	struct Node *left, *right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
    Node(int val,Node *l,Node *r):data(val),left(l),right(r){}
};


// Function to print the nodes of a complete
// binary tree in boundary traversal order
void boundaryTraversal(Node* root)
{
    if(!root)
        return;
	
    // If there is only 1 node print it
    // and return
    if (!(root->left) && !(root->right)) 
    {
        cout << root->data << endl;
        return;
    }

    // List to store order of traversed
    // nodes
    vector<Node*> list;
    list.push_back(root);

    // Traverse left boundary without root
    // and last node
    Node* L = root->left;
    while (L->left || L->right) {
        list.push_back(L);
        if(L->left)
            L = L->left;
        else
            L =L->right;
    }

    // BFS designed to only include leaf nodes
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (!(temp->left) && !(temp->right)) {
            list.push_back(temp);
        }
        if (temp->left) {
            q.push(temp->left);
        }
        if (temp->right) {
            q.push(temp->right);
        }
    }

    // Traverse right boundary without root
    // and last node
    vector<Node*> list_r;
    Node* R = root->right;
    while (R->right) {
        list_r.push_back(R);
        R = R->right;
    }

    // Reversing the order
    reverse(list_r.begin(), list_r.end());

    // Concatenating the two lists
    list.insert(list.end(), list_r.begin(),
                            list_r.end());

    // Printing the node's data from the list
    for (auto i : list) {
        cout << i->data << " ";
    }
    cout << endl;
    return;
	
}

// Driver code
int main()
{

	// Root node of the tree
	Node* root = new Node(20);

	root->left = new Node(8);
	root->right = new Node(22);

	root->left->left = new Node(4);
	root->left->right = new Node(12);

	root->right->left = new Node(10);
	root->right->right = new Node(25);

	boundaryTraversal(root);

	return 0;
}
