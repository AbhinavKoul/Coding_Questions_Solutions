// Start typing here
/*
arr[]                                     dest[]
[1,2,5,8]                                []


stratergy
1. take 2 closest pair (1,2) --> send this      [1,2]
  time = max(pair) + min(pair)(1 whole pass)
  
    keep doing this till arr is empty
    if only 2 elemts left
        --> max(pair)
*/
#include<iostream>
#include<vector>
#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
#define v vector
int minBridgePass(v<int> &arr)
{
    
    // int n = arr.size();
    priority_queue<int,v<int>,greater<int>> dest;
    int res = 0;
    while(arr.size() > 2)
    {
        //find indexes which are closest pair
        pair<int,int> idx;
        int min = 999999;
        
        // rtells us 1,2   {5,8}
        for(int i = 0;i<arr.size()-1;i++)
        {
            for(int j = i+1;j<arr.size();j++)
            {
                if(min > abs(arr[j] - arr[i]))
                {
                    min = abs(arr[j] - arr[i]);
                    idx.first = i;
                    idx.second = j;
                }
            }
        }
        cout<<"\t"<<arr[idx.first]<<arr[idx.second]<<" ";
        
        /*
        
        1 2                                5 8
        
        (5,8)                                              res = 13  
         
        */
        res += max(arr[idx.first], arr[idx.second]);
      
        dest.push(arr[idx.first]);
        dest.push(arr[idx.second]);
          arr.erase(find(arr.begin(),arr.end(),arr[idx.first]));
        arr.erase(find(arr.begin(),arr.end(),arr[idx.second]));
        
        int top = dest.top(); dest.pop();
        res += top;       
        cout<<"\t :"<<top;
        arr.push_back(top);
        
        
        
        
        cout<<"\n";
        for(int i = 0;i<arr.size();i++)
            cout<<arr[i];
    }
    
    res += max(arr[0],arr[1]);
    
    
    return res;
}

int main()
{
    
    v<int> arr = {1,2,5,8};
    
    cout<<" "<<minBridgePass(arr);
    return 0;
}