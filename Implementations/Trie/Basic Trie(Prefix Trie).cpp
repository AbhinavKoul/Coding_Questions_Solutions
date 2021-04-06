#include<iostream>
// #include<bits/stdc++.h>
#include<vector>
#include<queue>

#define v vector
#define INT_MAX 2147483647
using namespace std;

//making trienode
struct TrieNode
{
    char value;
    bool isWord;
    int count;
    // we do vector initialization like this as we are inside a
    //structure and we cant allocate space before the object is called!
    vector<TrieNode*> child = vector<TrieNode*>(26, nullptr);
    
    TrieNode(char v, bool b = false, int c = 1): value(v), isWord(b), count(1){}
};

//making a trie
struct Trie
{
    TrieNode* root = new TrieNode('\0', 0, INT_MAX);    //as 1st root node is null
    
    bool find(string s)
    {
        TrieNode *node = root;
        for(char c:s)
        {
            int index = c - 'a';
            // if initially empty/not in trie, add it in trie
            if(node->child[index] == nullptr) 
                return false;
            
            // if already in trie, go down the ladder of the tree
            node = node->child[index];
        }
        
        return(node!= nullptr && node->isWord);  //if last char is marked as end of word, then will return true
    }
    
    void insert(string s)
    {
        auto node = root;
        
        for(char c: s)
        {
            int index = c - 'a';
            // if character already in trie
            if(node->child[index])
            {
                node = node->child[index];  // increment node/ go down the ladder
                //keeping the count of that prefix(char) for all the elements inserted till now
                node->count++;  
                continue;
            }
            else    //if char not in trie, then we need to add it
            {
                auto newnode = new TrieNode(c);
                node->child[index] = newnode;
                node = newnode;
            }
            
        }
        //after all characters are inserted, the last level node(last char) we mark as the complete word
        node->isWord = true;
    }

    // Returns true if node has no children, else false
    bool isEmpty(TrieNode* node)
    {
        for (auto i : node->child)
            if(i != nullptr)
                return false;
        
        return true;
    }
    
    // Recursive function to delete a key from given Trie
    TrieNode* remove(TrieNode* node, string key, int depth = 0)
    {
        // If current node is empty
        if (!node)
            return nullptr;
    
        // If last character of key is being processed
        if (depth == key.size()) {
    
            // This node is no more end of word after
            // removal of given key
            if (node->isWord)
                node->isWord = false;
    
            // If given is not prefix of any other word, then we can remove all the elements till now
            if (isEmpty(node)) {
                delete (node);
                node = nullptr;
            }
    
            return node;
        }
    
        // If not last character, recur for the child
        // obtained using ASCII value
        int index = key[depth] - 'a';

        node->child[index] = remove(node->child[index], key, depth + 1);
    
        // If root does not have any child (its only child got
        // deleted), and it is not end of another word.
        if (isEmpty(node) && node->isWord == false) {
            delete (node);
            node = nullptr;
        }
    
        return node;
    }

    void del_trie_elemets(string str)
    {
        remove(root,str);
    }
};

// vector<string> prefix(vector<string> &A) 
// {
//     Trie my_t;
    
//     //insert all words in trie
//     for(string word:A)
//         my_t.insert(word);
        
//     vector<string> ans;
    
//     for(string word:A)
//         ans.push_back(my_t.compress(word));
        
//     return ans;
// }

int main()
{
    v<string> keys = { "the", "a", "there",
                      "answer", "any", "by",
                      "bye", "their", "hero", "heroplane" };

    int n = keys.size();
 
    Trie t1;
 
    // Construct trie
    for(string word : keys)
        t1.insert(word);
 
    // Search for different keys
    t1.find("the") ? cout << "Yes\n" : cout << "No\n";
    t1.find("these") ? cout << "Yes\n" : cout << "No\n";
    t1.find("heroplane") ? cout << "Yes\n" : cout << "No\n";
    t1.del_trie_elemets("heroplane");
    t1.del_trie_elemets("the");
    t1.find("the") ? cout << "Yes\n" : cout << "No\n";
    return 0;
}
