#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<climits>
using namespace std;
#define v vector


using namespace std;

int findMax(int n,vector<int> &arr,int k,int start,int end,v<v<int>>&dp){
    if(k==0)
        return 0;
    if(k>end-start+1)
        return 0;
    if(k==1)
        return arr[start]+arr[end];
    if(dp[k][start]!=-1)
        return dp[k][start];
    if(k==end-start+1){
        int sum=0;
        for(int i=start;i<=end;i++)
            sum+=2*arr[i];
        return dp[k][start] = sum;
    }
    int maxV=INT_MIN;
    for(int i=start;i<end;i++){
        int val = findMax(n,arr,k-1,i+1,end,dp);
        maxV=max(maxV,val+arr[start]+arr[i]);
        // cout<<maxV<<endl;
    }
    return dp[k][start]=maxV;
}

int findMin(int n,vector<int> &arr,int k,int start,int end,vector<vector<int>>&dp){
    if(k==0)
        return 0;
    if(k==1)
        return arr[start]+arr[end];

    if(dp[k][start]!=-1)
        return dp[k][start];

    if(k==end-start+1){
        int sum=0;
        for(int i=start;i<=end;i++)
            sum+=2*arr[i];
        return dp[k][start]=sum;
    }
    int minV=INT_MAX;
    for(int i=start;i<end;i++){
        int val = findMin(n,arr,k-1,i+1,end,dp);
        if(val!=INT_MAX)
          minV=min(minV,val+arr[start]+arr[i]);
    }
    // cout<<start<<" "<<end<<" "<<k<<" "<<minV<<endl;
    return dp[k][start]=minV;
}


int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int maxV = findMax(n,arr,k,0,n-1,dp);
        
        for(int i=0;i<k+1;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=-1;
            }
        }
        int minV = findMin(n,arr,k,0,n-1,dp);
        cout<<maxV - minV;
    }
    
    return 0;
}

// ----------------------------------------------------------------------------------------------------------------------- //
int maxCandies(const v<int> &arr, int k, int start,int end)
{
    //base
    if(start > end)
        return 0;
    if(k == 0)
        return 0;
    
    if(k == 1)
        return arr[start] + arr[end];
    
    if(k == end - start + 1)
    {
        int sum = 0;
        for(auto i : arr)
            sum += i;
        
        return sum;
    }

    //normal
    int maxRes = -99999;
    int res = 0;
    // maxRes = max(maxRes,res+maxCandies(arr,k-1,start+1,end));
    for(int i = start;i<=end - k +1;i++)
    {
        if(start != i)
            res = arr[start] + arr[i] + maxCandies(arr,k-1,i+1,end);
        else
            res = arr[i] + maxCandies(arr,k-1,i+1,end);

        maxRes = max(maxRes,res);
    }

    return maxRes;

}
int minCandies(const v<int> &arr, int k, int start,int end)
{
    //base
    if(start > end)
        return 0;
    if(k == 0)
        return 0;
    
    if(k == 1)
        return arr[start] + arr[end];
    
    if(k == end - start + 1)
    {
        int sum = 0;
        for(auto i : arr)
            sum += i;
        
        return sum;
    }

    //normal
    int minRes = 99999;
    int res = 0;
    // maxRes = max(maxRes,res+maxCandies(arr,k-1,start+1,end));
    for(int i = start;i<=end - k +1;i++)
    {

        res = arr[start] + arr[i] + maxCandies(arr,k-1,i+1,end);

        minRes = min(minRes,res);
    }

    return minRes;

}
int main()
{
    v<int> arr = {1,3,5,1};

    cout<<"hellp: "<<maxCandies(arr,2,0,3) - minCandies(arr,2,0,3);

    return 0;
}