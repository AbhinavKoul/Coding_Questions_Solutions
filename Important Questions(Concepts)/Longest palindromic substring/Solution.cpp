//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
#define v vector

using namespace std;

// DP SOLUTION : https://leetcode.com/problems/longest-palindromic-substring/discuss/147548/Direct-c%2B%2B-DP
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==0) return "";
        int i = 0, j = 0;
        int n = s.size();
        //initialize P[n][n], we only need half of P, and initialize it like: (e.g. : s="abbc")
        bool P[n][n]={false};
        for(int x = 0;x<n;x++){
            P[x][x]=true;
            if(x==n-1) break;
            P[x][x+1] = (s[x]==s[x+1]);
        }
        //dp 
        for(int i = n-3; i>=0; --i){
            for(int j = i+2;j<n; ++j){
                P[i][j] = (P[i+1][j-1] && s[i]==s[j]);     
            }
        }
        //get maxstr result
        int max = 0;
        string maxstr = "";
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(P[i][j]==true and j-i+1>max){
                    max = j-i+1;
                    maxstr = s.substr(i,j-i+1);
                }
            }
        }
        return maxstr;
    }
};


// expand around center
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 1)
            return s;
        
        int endptr,fixptr;
        string res = "";
        for(int i = 0;i<n;i++)
        {
            for(int j =i+1;j<n;j++)
            {
                int end_const = endptr = j;
                int start_const = fixptr = i;

                while(fixptr < endptr)
                {
                    if(s[fixptr] == s[endptr])
                    {
                        fixptr++;
                        endptr--;
                    }
                    else
                        break;
                }

                if(fixptr >= endptr)
                    
                    
                    
                {
                    int diff = end_const - start_const + 1;
                    if(diff > res.size())
                    {
                        res = "";
                        res += s.substr(start_const,diff);
                    }
                }
            }
            
        }
        if(res == "")
            return res + s[0];
        else
            return res;
        
    }
};