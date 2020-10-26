/*
When arrray given has +ve and -ve elements both => then find out the max subarray sum along with the index range
*/
#include<iostream>
#include<vector>
using namespace std;
#define v vector


v<int> kandanesAlgo(const v<int>& arr)
{
    int local_max = 0;
    int global_max = 0;
    int n = arr.size();
    int start = 0, end = 0;
    int slowPtr = 0;

    for(int i = 0; i<n;i++)
    {
        local_max += arr[i];

        if(global_max < local_max)
        {            
            global_max = local_max;
            end = i;
            start = slowPtr;
        
        }
        if (local_max < 0)
        {
            local_max = 0;
            slowPtr += 1;  
        }
    }

    v<int> result = {global_max,start,end};
    return result;
} 


int main()
{
    v<int> arr = {-2,-3,4,-1,-2,1,5,-3};
    v<int> res = kandanesAlgo(arr);

    cout<<endl;
    for(auto i : res)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}