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

/*
O(n) TIME
O(1) space
*/
int majorityElement_MOORESvOTING(const vector<int> &A) {
    int n = A.size();
    
    int ansIndex = 0;
    int cnt = 1;
    
    for(int i = 1;i<n;i++)
    {
        if(A[i] == A[ansIndex])
            cnt++;
        else
            cnt--;
        
        //maybe a new winner,lets seee
        if(cnt == 0)
        {
            ansIndex = i;
            cnt =1;
        }
    }
    
    // now need to check actually if the final element has more elements or not
    // cause eg [1,2,3] last we will have 3, but that doesnt make it the answer
    
    cnt = 0;
    for(auto i : A)
    {
        if(i == A[ansIndex])
            cnt++;
    }
    
    if(cnt > n/2)
        return A[ansIndex];
        
    return -1;
}
