#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
// Segment treee approach
// O(NlogN) https://www.codingninjas.com/codestudio/problem-details/order-of-people-heights_1170764



// Time : O(N2) ---- sorting meathod!!
vector<int> order(vector<int> &A, vector<int> &B) {
    vector<int> vec;
    priority_queue<pair<int,int>> pq;   //maxHeap
    
    for(int i=0;i<A.size();i++)     //O(NLOG(N))
        pq.push({A[i],B[i]});
    
    int n=A.size();
    
    int temp=n;
    int x=0;
    
    //O(N2)
    while(temp--)   //O(N)
    {
        int top=pq.top().first;
        int val=pq.top().second;
        pq.pop();
        vec.insert(vec.begin()+val,top);    //O(N) Insertion
    }
    return vec;
}
