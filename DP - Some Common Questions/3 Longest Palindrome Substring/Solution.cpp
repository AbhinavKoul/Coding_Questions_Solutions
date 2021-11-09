#include<iostream>
#include<vector>
#include<algorithm>
#define v vector
using namespace std;

int longestValidParentheses(string s) 
{
    int n = s.length();
    if(n == 0 || n==1)
        return 0;

    v<int> dp(n);
    dp[0] = 0;
    int currMax = INT_MIN;
    
    for(int i = 1;i<n;i++)
    {
        if(s[i] == '(')
            dp[i] = 0;
        else
        {
            if(s[i-1] == '(')
                dp[i] = i-2<0? 2 : dp[i-2]+2;
            else
            {
                int pos = (i - 1) - dp[i-1];
                if(pos < 0)
                    dp[i] = 0;
                else
                {
                    if(s[pos] == '(')
                        dp[i] = dp[i-1] + 2 + (pos - 1 > 0?dp[pos-1]:0);
                    else
                        dp[i] = 0;
                }
                
            }
        }
            
        currMax = max(currMax,dp[i]);
    }
    
    return currMax;
    
}