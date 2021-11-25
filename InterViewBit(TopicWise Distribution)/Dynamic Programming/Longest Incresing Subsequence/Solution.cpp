#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
#define v vector
#define um unordered_map
#define mod 1000000007
#define ll long long int
using namespace std;

//O(NLOGN)
int BEST_LOWER_BOUND_APPROACH(const vector<int> &v) {
    if (v.size() == 0) // boundary case
        return 0;
 
    std::vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail
 
    tail[0] = v[0];
 
    for (int i = 1; i < v.size(); i++) {
 
        // Do binary search for the element in
        // the range from begin to begin + length
        auto b = tail.begin(), e = tail.begin() + length;
        auto it = lower_bound(b, e, v[i]);                  //log(N)
 
        // If not present change the tail element to v[i]
        if (it == tail.begin() + length)
            tail[length++] = v[i];
        else
            *it = v[i];
    }
 
    return length;
}

//O(N2)
int Top_Down_DP_Appraoch(const vector<int> &A) {
    int n = A.size();
    v<int> arr(n,1);
    
    for(int i = n-2;i>=0;i--)
    {
        for(int j = i+1;j<n;j++)
        {
            if(A[i] < A[j])
            {
                arr[i] = max(arr[i],arr[j] + 1);
            }
        }
    
    }
    
 
    return *max_element(arr.begin(),arr.end());
}

//O(N2)
int Bottom_Up_DP_Approach(const vector<int> &A) {
    int n = A.size();
    v<int> arr(n);
    
    arr[0] = 1;
    for(int i = 1;i<n;i++)
    {
        int lis_before = 0; // this can be removed as shown above approach
        for(int j = 0;j<i;j++)
        {
            if(A[j] < A[i])
            {
                lis_before = max(lis_before,arr[j]);
            }
        }
        
        arr[i] = lis_before + 1;
    }
    
 
    return *max_element(arr.begin(),arr.end());
}