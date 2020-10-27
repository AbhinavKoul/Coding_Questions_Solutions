#include<iostream>
#include<vector> 
#include<unordered_map>
#define v vector
#define um unordered_map
using namespace std;

pair<int,int> subarrayHavingSum_CDF(const v<int> &arr, int sum)
{
    /*
    Time : O(N)
    Space: O(N)
    */
    um<int,int> map;
    int localSum = 0;
    
    map[0] = -1;

    for(int i =0;i<arr.size();i++)
    {
        localSum += arr[i];
        
        if(map.find(localSum - sum) != map.end())
        {
            return make_pair(map[localSum - sum]  + 1,i);
        }

        map[localSum] = i;
    }
    
    return make_pair(-1,-1);
}

v<int> subarrayHavingSum_2Pointers(const v<int> &arr, int sum)
{
    /*
    Time : O(N2) ==>Much efficient due to 2 pointers approach
    Space: O(1)
    */
    int slowptr = 0,fastptr = 0;
    int localMax = 0;

    for(fastptr = 0;fastptr<arr.size();fastptr++)
    {
        localMax += arr[fastptr];

        while ((localMax > sum) && (slowptr<fastptr))
        {
            localMax -= arr[slowptr++];
        }

        if(localMax == sum)
            break;
    }

    if(localMax == sum)
        return {slowptr,fastptr};
    else
    {
        cout<<"sum Not inside subarray";
        return{-1,-1};
    }
    
}

int main()
{
    v<int> inp = {1,2,3,7,5};
    // v<int> res = subarrayHavingSum_2Pointers(inp,99);

    pair<int,int> result = subarrayHavingSum_CDF(inp,3);
    // cout<<endl;
    // for(auto i:res)
    //     cout<<i<<" ";

    // cout<<"khatma";

    cout<<"Answer is: "<<result.first<<" "<<result.second;
    return 0;
}