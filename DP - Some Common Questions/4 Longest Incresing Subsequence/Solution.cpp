#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
#define v vector
#define um unordered_map
#define endl "\n"
#define pb push_back
#define mod 4294967296

using namespace std;
//LIS --> NLOGN approach
int LongestIncreasingSubsequenceLength(vector<int> A)  
{  
    if (A.size() == 0)  
        return 0;  
  
    int n = A.size();
    vector<int> tail(n, 0);  
      
    tail[0] = A[0];  //1st element goes directly

    int length = 1; // always points empty slot in tail  --> thus has index of next length not yet included

    for (int i = 1; i < A.size(); i++) 
    {  
  
        // Do binary search for the element in  
        // the range from begin to begin + length 
        auto b = tail.begin(), e = tail.begin() + length; 
        auto it = lower_bound(b, e, A[i]);  
              
        // If not present b/w b and e --> change the tail element to A[i]  
        if (it == tail.begin() + length) 
            tail[length++] = A[i];  
        else   
            *it = A[i];  
    }  
  
    return length;  
}  

//LIS O(N2) Approach
int LongestIncresingSubsequence(v<int> arr)
{
    int n = arr.size();

    v<int> lis(n,1);    // for each element initially LIS ending at that position is the element itself

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<i;j++)
        {
            if(arr[j] < arr[i])
                lis[i] = max(lis[j] + 1,lis[i]);
        }
    }

    return *max_element(lis.begin(),lis.end());
}
int main()
{

    return 0;
}