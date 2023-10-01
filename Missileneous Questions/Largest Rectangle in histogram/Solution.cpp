#include<iostream>
// #include<bits/stdc++.h>
#include<vector>
#include<queue>
#include<stack>
#define v vector
using namespace std;

//better understanding solution
int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    st.push(0);
    heights.push_back(0);
    int largestArea = INT_MIN;
    int i = 1;
    int n = heights.size();
    while(i < n)
    {
        if(st.empty() || heights[i] >= heights[st.top()])
        {
            st.push(i);
            i++;
        }
        else //find left and right borders
        {
            int largestIdx = st.top(); st.pop();
            int left = st.empty()?-1:st.top();    //find left boundry index
            int right = i - 1; //get back to current one;
            int area = heights[largestIdx]*(right - left);
            largestArea = max(area,largestArea);
        }
    }
    return max(largestArea,0);
}
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