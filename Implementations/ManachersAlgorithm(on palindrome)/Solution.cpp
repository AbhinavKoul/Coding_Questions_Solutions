#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define v vector
class Solution {
public:
    string longestPalindromeManachersAlgorithm(string s) {
        int n = s.size();
        string str = "#";

        for(int i = 0;i<n;i++)
        {
            str.push_back(s[i]);
            str.push_back('#');
        }

        int maxLength = 0;
        int maxCenter = 0;
        int center = 0;
        int right = 0;

        v<int> dp(str.size(),0); //iniitally everything is 0

        for(int i = 0;i<str.size();i++) //check each center point
        {
            int left = 2*center - right;

            if(i<=right) //inside the bounds
            {
                dp[i] = min(dp[left],right - i);   //would be minimum of its left mirror
            }

            //we need to do palindrome check after the already checked ones
            int l = i - (dp[i] + 1);
            int r = i + (dp[i] + 1);
            
            while(l>=0 && r < str.size() && str[l] == str[r])
            {
                l--;
                r++;
                dp[i]++;
            }

            if(dp[i] > maxLength)
            {
                maxCenter = i;
                maxLength = dp[i];
            }

            //new center?
            if(i + dp[i] > right)
            {
                right = i + dp[i];
                center = i;
            }
        }
        string res = str.substr(maxCenter - maxLength, 2*maxLength);
        // erase(res, '#'); //c++20 we can do this
        //or
        //remove returns the iterator of new end of string, but doesnt actually delete the rest elemetns and keep it at the end
        res.erase(remove(res.begin(),res.end(),'#'),res.end()); 
        return res;
    }
};