#include <iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
#define v vector

v<int> calculateSpan(v<int> price)
{
    int n = price.size();
    v<int> S(n);

    // Create a stack and push index of first
    // element to it
    stack<int> st;
    st.push(0);
 
    // Span value of first element is always 1
    S[0] = 1;
 

    // Calculate span values for rest of the elements
    for (int i = 1; i < n; i++) 
    {
        // Pop elements from stack while stack is not
        // empty and top of stack is smaller than
        // price[i]
        while (!st.empty() && price[st.top()] < price[i])
            st.pop();
 
        // If stack becomes empty, then price[i] is
        // greater than all elements on left of it,
        // i.e., price[0], price[1], ..price[i-1].  Else
        // price[i] is greater than elements after
        // top of stack
        S[i] = (st.empty()) ? (i + 1) : (i - st.top());
 
        // Push this element to stack
        st.push(i);
    }
}
 