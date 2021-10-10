#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<queue>
// using namespace std;
#define v vector
using namespace std;

int count_ways(int index,int cnt,v<v<int>> dp,int n,int m,int k)
{
    //base confition
    if(index == n)
    {
        if(cnt == k)    //condiion met
            return 1;

        return 0;
    }

    if(dp[index][cnt] != -1)
        return dp[index][cnt];
    

    int res = 0;

    //same colour
    res += count_ways(index + 1,cnt,dp,n,m,k);

    //diff colour
    res += (m-1) * count_ways(index + 1,cnt+1,dp,n,m,k);

    dp[index][cnt] = res;

    return res;

}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;

    v<v<int>> dp(n+1,v<int>(4,-1));

    cout<<m*count_ways(0,0,dp,n,m,k);

    return 0;
}