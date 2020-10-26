#include<iostream>
#include<string>
#include<vector>
#define v vector
using namespace std;

int dpSolHelper(const string &str,int i,v<int> &dp)
{
    //base
    if(i>=str.length())
        return 1;
    
    if(dp[i] != NULL)
        return dp[i];
    
    if(str[i] == '0')
        return 0;
    
    //general
    int res = dpSolHelper(str,i+1,dp);

    if(stoi(str.substr(i,2))<=26 && (i+2<=str.length()))
        res += dpSolHelper(str,i+2,dp);
    
    dp[i] = res;
    return dp[i];
}

int dpSolution(const string &str)
{
    int n = str.length();
    v<int> dp(n,NULL);
    return dpSolHelper(str,0,dp);
}

int main()
{
    string arr = "012245";
    cout<<"HELLO : "<< dpSolution(arr)<< " ";
    return 0;
}