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
        
        return node->isWord;
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
    
    // to return our answer in string format
    string compress(string s)
    {
        string ans = "";
        auto node = root;
        
        for(char c:s)
        {
            int index = c - 'a';
            ans.push_back(c);
            // since we need to find unique prefix, so whichever is counted only once, is our answer
            if(node->child[index]->count == 1)
                break;
                
            node = node->child[index];  //go down the trie, till we get to know the answer
        }
        return ans;
    }
};

vector<string> prefix(vector<string> &A) 
{
    Trie my_t;
    
    //insert all words in trie
    for(string word:A)
        my_t.insert(word);
        
    vector<string> ans;
    
    for(string word:A)
        ans.push_back(my_t.compress(word));
        
    return ans;
}
