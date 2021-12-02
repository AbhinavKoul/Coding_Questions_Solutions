#include<vector>
using namespace std;

struct Node {
    int key, val;
    Node* next;
    Node(int k, int v, Node* n) {
        key = k;
        val = v;
        next = n;
    }
};
class MyHashMap {
public:
    //both these should be prime in order to make a balanced structure in our array
    const static int size = 19997;
    const static int mult = 12582917;

    //list of array, so that if colliion occurs, we still have  a chain having key and values
    vector<Node*> data;

    MyHashMap() {
        data.clear();
        data.resize(size);
    }

    //hashing fn
    int hash(int key) {
        return (int)((long)key * mult % size);
    }

    //input
    void put(int key, int val) 
    {
        //if already exist in map, then you need to update that key value, so we first remove and then add
        remove(key);

        int h = hash(key);
        Node* node = new Node(key, val, data[h]);
        
        data[h] = node;
    }    

    //extract
    int get(int key) {
        int h = hash(key);
        Node* node = data[h];
        
        //traverse all the nodes at the current hash index
        for (; node != nullptr; node = node->next)
            if (node->key == key) 
                return node->val;
        
        return -1;
    }   

    void remove(int key) {
        int h = hash(key);
        Node* node = data[h];
        
        //if nothing present at that hash index
        if (node == nullptr) 
            return;

        //if 1st node only has key; just remove this and point it to next
        if (node->key == key) 
        {
            data[h] = node->next;
            //free up space
            delete(node);
        }
        else
        {
            for (; node->next != nullptr; node = node->next)
                if (node->next->key == key) {
                    Node *temp = node->next;
                    node->next = node->next->next;
                   
                    //deallocation of space
                    delete(temp);
                    return;
                }
        } 
            
    }
};