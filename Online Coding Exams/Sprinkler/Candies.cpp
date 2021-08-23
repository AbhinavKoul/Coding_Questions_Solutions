#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
using namespace std;
#define v vector

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