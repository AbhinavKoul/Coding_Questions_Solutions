#include<iostream>
#include<string>
#include<vector>
#define v vector
using namespace std;
class Solution {
/*
https://leetcode.com/submissions/detail/459363037/
*/
public:
    int numDecodings(string s) {
        int n = s.size();
        v<int> res(n+1);
        res[n] = 1;
        
        if(s[n-1] == '0')
            res[n-1] = 0;
        else
            res[n-1] = 1;
        
        for(int i = n-2;i>=0;i--)
        {
            if(s[i] == '0')
                res[i] = 0;
            else if(stoi(s.substr(i,2)) <= 26)
            {
                res[i] = res[i+1] + res[i+2];
            }
            else
            {
                res[i] = res[i+1];
            }
        }
        
        return res[0];
        
    }
};