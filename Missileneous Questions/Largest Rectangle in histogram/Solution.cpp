#include<iostream>
// #include<bits/stdc++.h>
#include<vector>
#include<queue>
#include<stack>
#define v vector
using namespace std;

int largestRectangleArea(vector<int> &A) 
{
    A.push_back(0);
    stack<int> st;
    int res = INT_MIN;
    for(int i=0;i<A.size();i++)
    {
        while(!st.empty() && A[i]<A[st.top()])
        {
            int x = st.top();
            st.pop();
            int index = st.size() == 0 ? -1 : st.top();
            res = max(res,A[x]*(i-index-1));
        }
        st.push(i);
    }
    return res;
}