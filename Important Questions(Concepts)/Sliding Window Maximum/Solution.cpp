#include<iostream>
#include<vector>
#include<queue>
using namespace std;


vector<int> slidingMaximum_dqueue_version(const vector<int> &A, int w) 
{
    /*
    Time : O(N)
    Since there will be n additions in dqueue and n deletions in dqueue
    ie. 2n operations
    */
    int n = A.size();
    vector<int> B;
    
    if (n < w) 
        return A;
    
    B.resize(n - w + 1);
    deque<int> Q;   //intitialize double ended queue
    
    for (int i = 0; i < w; i++)     //keep max element index in front of dequeue
    {
        while (!Q.empty() && A[i] >= A[Q.back()])
            Q.pop_back();
        Q.push_back(i);
    }
    for (int i = w; i < n; i++) 
    {
        B[i - w] = A[Q.front()];    //store max element in that window to vector
        while (!Q.empty() && A[i] >= A[Q.back()])   //same like loop 1
            Q.pop_back();
        while (!Q.empty() && Q.front() <= i - w)    //removing max elemenes which are outside window
            Q.pop_front();
        Q.push_back(i);
    }
    B[n - w] = A[Q.front()];    //for last element
    return B;
}

vector<int> slidingMaximum_priorityQueue_Version(const vector<int> &A, int B)
{
    /*
    Time : O(NlogN) ==>due to heap
    */
    int i=0, j=0, ans=INT_MIN;
    priority_queue<pair<int,int>> maxh; //Max Heap initialization
    vector<int> v;
    
    while(j<A.size())
    {
        maxh.push({A[j],j});    // push the current elelemtn in max heap
    
        if(j-i+1 < B) // if window size is less
            j++;    
        else if(j-i+1 == B) //when window is reached
        {
            v.push_back(maxh.top().first);  //return the max element in the window
            if(maxh.size()>0 && maxh.top().second<=i)   // remove elements outside of window
            {
                while(maxh.size()>0 && maxh.top().second<=i) 
                    maxh.pop();
            }
            i++;
            j++;
        }
    }
    return v;
}

