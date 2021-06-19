#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<set>
#include<queue>
#include<math.h>
using namespace std;
#define v vector
bool mycompare(const v<int> &a,const v<int>& b)
{
    if(a[1] == b[1])
    {
        if(a[0] < b[0])
            return true;
        else
            return false;
    }

    if(a[1] < b[1])
        return true;
    else
        return false;
}
int minimumCost(int n,int m,vector<vector<int>>teams)
{
    sort(teams.begin(),teams.end(),mycompare);

    // long long dp[m];
    v<long long> dp(m);

    for(int i=0;i<teams.size();i++)
    {
        bool flag = false;

        int curr = teams[i][1] - teams[i][0] + 1;

        long long constant = 1e13;

        dp[i] = -1;

        if(teams[i][0] == 1)
        {
            dp[i] = curr;
            continue;
        }

        for(int j=i-1;j>=0;j--)
        {
            if(teams[j][1] - teams[i][0] >= -1)
            {
                if(dp[j] != -1)
                {
                    long long val = dp[j]+curr;
                    constant = min(val,constant);
                    flag = true;
                }
            }
            else
            {
                break;
            }
        }

        if(flag)
        {
            dp[i] = constant;
        }
    }

    long long ans = 1e13;

    for(int i=0;i<m;i++)
    {
        if(teams[i][1]==n && dp[i]!=-1){
            ans = min(ans,dp[i]);
        }
    }

    if(ans == 1e13)
    {
        return -1;
    }

    return ans;
}

int main() {
    
    //cout<<"Hello World";
    int n=10,m =5;
    vector<vector<int>>v={{1,9},{2,10},{1,4},{4,6},{6,10}};
    cout<<"hello : "<<minimumCost(n,m,v);

    return 0;
}