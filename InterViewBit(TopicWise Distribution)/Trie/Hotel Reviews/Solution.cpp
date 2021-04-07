#include<iostream>
// #include<bits/stdc++.h>
#include<vector>
#include<queue>

#define v vector
using namespace std;

//making trienode
struct TrieNode
{
    char value;
    bool isWord;
    // we do vector initialization like this as we are inside a
    //structure and we cant allocate space before the object is called!
    vector<TrieNode*> child = vector<TrieNode*>(26, nullptr);
    
    TrieNode(char v, bool b = false): value(v), isWord(b){}
};

//making a trie
struct Trie
{
    TrieNode* root = new TrieNode('\0');    //as 1st root node is null
    
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
};

/*
Convert the underscore to spaces in a word
*/
void convert(string &str)
{
    //Convert _ to spaces
    for(int i=0; i<str.size(); i++)	 
    {
    	if(str[i] == '_')	
    	     str[i] = ' ';
    }
}

bool cmp(pair<int,int> a , pair<int,int> b)
{   // stable sort function!!!
    if(a.first == b.first)
    {
        return a.second < b.second; // since we need to mentain relative ordering of index
    }
    
    return a.first > b.first;   // as 1st we sort on bases of most count
}
vector<int> solve(string A, vector<string> &B) {
    Trie t1;
    v<int> res;
    v<pair<int,int>>v1;
    string ele;
    
    string word;
    stringstream ss;
    ss.clear();
    
    /*
    when you enter string sepatated by space,
    string stream automaticaxlly extract words separated by spaces inside that
    */
    
    convert(A); // now whole string is separated by spaces
    ss<<A;  //PUT THE ENTIRE STRING IN string stream
    while(ss>>word)
        t1.insert(word);
        
    int count;
    for(int i = 0;i<B.size();i++)
    {
        convert(B[i]);
        //clear string stream so no unwated characters come
        ss.clear();
        
        ss<<B[i];
        
        count = 0;
        while(ss>>word)
        {
            if(t1.find(word))
                count++;
        }
        
        v1.push_back({count,i});
    }
    
    sort(v1.begin(),v1.end(),cmp);
    
    for(int i = 0;i<B.size();i++)
        res.push_back(v1[i].second);
        
    return res;
    
    
}
