#include<iostream>
#include<vector>
using namespace std;
/*
Time : O(N)
Space: O(1)
*/
int firstMissingPositive(vector<int> &ar) {
    int n=ar.size();
    for(int i=0;i<n;i++)
        if(ar[i]<1)
            ar[i]=n+1;
            
    for(int i=0;i<n;i++)
        if(abs(ar[i]-1)<n)
            ar[abs(ar[i])-1]*=-1;
    
    for(int i=0;i<n;i++)
        if(ar[i]>0)
            return i+1;
    
    return n+1;
}
