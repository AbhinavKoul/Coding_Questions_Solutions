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

// buy at local minima and sell at global maxima
int maxProfit(const vector<int> &A) {
    int n = A.size();
  
    if(n==0)
        return 0;
    int res = 0;
    
    int localMin = A[0];
    int localProfit = 0;
    for(int i = 1;i<n;i++)
    {
        if(A[i - 1] <= A[i])
        {
            localProfit = max(localProfit,A[i] - localMin);
        }
        else
        {
            localMin = A[i];
            res += localProfit;
            localProfit = 0;
        }
        
    }
    
    res += localProfit;
    
    return res;
}
