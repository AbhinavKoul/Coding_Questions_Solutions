#include<iostream>
#include<vector>
#include<set>

#define v vector
using namespace std;

int countWays(int n, set<int> steps)
{
    //1 based indexing
    v<int> dp(n+1);

    dp[0] = 1;

    for(int i = 1; i<= n;i++)
    {
        int val = 0;
        for(auto j : steps)
        {
            if(i - j >= 0)
                val += dp[i-j];
        }

        dp[i] = val;
    }

    return dp[n];
}

int main()
{
    return 0;
}