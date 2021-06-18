#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;
#define v vector
//LINK : https://leetcode.com/problems/can-make-palindrome-from-substring/
class Solution {

public:
    #define v vector
    vector<bool> canMakePaliQueries_BITVECTOR(string s, vector<vector<int>>& queries) {
    
        // we realize that we need to know only about if character is odd or even
        int n = s.size();
        v<bitset<26>> dp(n);
        
        int mask = s[0] - 'a';
        dp[0] ^= 1<<mask;
        
        //making map
        for(int i = 1;i<n;i++)
        {
            int mask = s[i] - 'a';
            dp[i] = dp[i-1];
            dp[i] ^= (1<<mask);
        }
        
        v<bool> ans;
        
        for(auto val : queries)
        {
            int left = val[0], right = val[1], k = val[2];
            
            
            bitset<26> res = left == 0? dp[right] : dp[right] ^ dp[left - 1];
            
            if(res.count()/2 <= k)
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        
        return ans;
    }
    
    vector<bool> canMakePaliQueries_MAPPING(string s, vector<vector<int>>& queries) {
        int n = s.size();
        v<bool> res;
        v<v<int>> mapping_count(n,v<int>(26,0));    //USE THIS AS ACCESING IS WAYY FASTER
        mapping_count[0][s[0] - 'a'] += 1;
        
        for(int i = 1;i<n;i++)
        {
            int pos = s[i] - 'a';
            mapping_count[i].assign(mapping_count[i-1].begin(),mapping_count[i-1].end());
            mapping_count[i][pos] += 1;
    
        }
        
       
        for(auto val : queries)
        {
            int left = val[0], right = val[1], k = val[2];
            int diffirent_elements = 0;
            
            for(int i = 0;i<26;i++)
            {
                //even no of new elelmts, you can arrange along mirron line
                //odd no you need to add 1 or sometjhing
                if(left == 0)
                    diffirent_elements += (mapping_count[right][i])%2;
                else
                    diffirent_elements += (mapping_count[right][i] - mapping_count[left - 1][i])%2;
            }
            //this is total no of changes we need, but in reality if we do only once!
            // our palindrome would be ready!
            // abbc
            // -> diffirence = a : 1 c : 1 ==> both add up to 2
            // we just need to change either of them ie 2/2 = 1
            
            // aaabbc
            // ->diff = a:3(2 of these a can be aranged easily --> only issue is with odd one out) c : 1
            
            if((diffirent_elements/2) <= k)
                res.push_back(true);
            else
                res.push_back(false);
        }
        
        return res;
    }
};