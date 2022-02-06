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
// TOP - DOWN COMPLETE Brute force O(2^N) <-- for every partyition we are checing if it can be included or not
class Solution {
public:
    //backtrack --> bruteforce
    bool backtrack(string s,int i,const set<string>&dict)
    {
        int n = s.length();
        if(i >= n)
            return true;
        
        //check if word is getting made?
        for(int j = i+1;j<=n;j++)
        {
            if(dict.count(s.substr(i,j-i)) == 1)
            {
                if(backtrack(s,j,dict))
                    return true;
            }
        }
        
        
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict(wordDict.begin(),wordDict.end());
        
        //leap of faith
        return backtrack(s,0,dict);
        
    }
};

// TOP- DOWEN MEMORIZATION O(N2 * N) <=== N3 (Best time approach)
class Solution {
public:
    //backtrack --> bruteforce with memorization
    bool backtrack(string s,int i,const set<string>&dict,vector<int>& memo)
    {
        int n = s.length();
        //base
        if(i >= n)
            return true;
        if(memo[i] != -1)
            return memo[i];
        
        //check if word is getting made?
        for(int j = i+1;j<=n;j++)
        {
            if(dict.count(s.substr(i,j-i)) == 1)
            {
                if(backtrack(s,j,dict,memo))
                {
                    memo[i] =  1;
                    return memo[i];
                }
                    
            }
        }
        
        
        memo[i] = 0;
        return memo[i];
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict(wordDict.begin(),wordDict.end());
        vector<int> memo(s.size(),-1);
        //leap of faith
        return backtrack(s,0,dict,memo);
        
    }
};

// BOTTOM UP GAP DIAGONAL APPROACH O(N2 * N) --> N3 --> but still a bit slow than top down cause all subinstances are getting calculated here
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
       
        int n = s.length();
        
        set<string> dict(wordDict.begin(),wordDict.end());
        
        v<v<bool>> dp(n,v<bool>(n,false));
        
        //gap diagonal
        for(int g = 0;g<n;g++)
        {
            for(int i = 0,j = g; j<n; j++,i++)
            {
                if(g == 0)
                {
                    if(dict.count(s.substr(i,j-i+1)) == 1)
                        dp[i][j] = true;
                    else
                        dp[i][j] = false;
                }
                else    //normal
                {
                    //check full word
                    if(dict.count(s.substr(i,j-i+1)) == 1)
                    {
                        dp[i][j] = true;
                        continue;
                    }
                    
                    
                    //check divisions
                    dp[i][j] = false;
                    for(int k = i;k<j;k++) // [i .. j] --> div are 1 less, thus we wont incluide j, we are calculating that 
                    {
                        dp[i][j] = (dp[i][k] && dp[k+1][j]);
                        
                        if(dp[i][j])
                            break;
        
                    }
                }
                
            }
        }
        
        
        return dp[0][n-1];
        
    }
};