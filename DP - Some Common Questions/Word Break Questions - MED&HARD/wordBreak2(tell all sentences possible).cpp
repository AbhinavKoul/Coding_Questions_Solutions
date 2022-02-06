#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
#include<set>
#define v vector
#define um unordered_map
#define endl "\n"
#define pb push_back
#define mod 4294967296

using namespace std;

class Solution {
public:
    void backtrack(const string& s,int i,const set<string> &dict,v<string>& result,string& str)
    {
        int n = s.length();
        // BASE CASE
        if(i>=n)
        {
            str.pop_back(); // <------ remove extra ending space
            // cout<<"<<<>>>"<<str<<"\n";
            result.push_back(str);
            str.push_back(' ');// <----- add that extra space so deleting task doesnt go out of bound in fn
            
            return;
        };
        
        //NORAMAL CASE
        // check the string after j till the end. (we do <=n for j as substring fn needs the number of characters needed after start)
        for(int j = i;j<=n;j++)
        {
            if(dict.count(s.substr(i,j-i)) == 1)
            {
                // add entire string and a space
                str.append(s.substr(i,j-i));
                str.push_back(' ');
                // cout<<str<<" <- \n";
                backtrack(s,j,dict,result,str);
                
                //backtrack here and delete characters added and a space which was added
                str.erase(str.length() - j + i - 1);
                // cout<<"\n -> "<<str;
            }
        }
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> dict(wordDict.begin(),wordDict.end());
        
        v<string> result;
        string str = "";    //<==== instance of that solution
        backtrack(s,0,dict,result,str);
        
        return result;
    }
};