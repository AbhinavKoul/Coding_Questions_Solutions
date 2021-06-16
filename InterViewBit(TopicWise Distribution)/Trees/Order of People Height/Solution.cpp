#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
// Segment treee approach
// O(NlogN) https://www.codingninjas.com/codestudio/problem-details/order-of-people-heights_1170764
#define v vector

void builtTree(v<int>&st,int curNode,int start,int end) //O(N)
{
    //if leaf node
    if(start == end)
    {
        st[curNode] = 1;  //since all leaf nodes are intially open
    }
    else
    {
        int mid = (start + end)/2;
        
        builtTree(st,2*curNode + 1,start,mid);
        builtTree(st,2*curNode + 2,mid+1,end);
        
        st[curNode] = st[(2*curNode + 1)] + st[(2*curNode + 2)];
    }
}
int findEmptySlot(v<int> &st,int curNode,int start,int end,int k)
{
    if(st[curNode] >= k)
    {
        st[curNode] -= 1;   //updation on the go!
        
        if(start == end)    //if leaf node
            return start;
            
        int mid = (start + end)/2;
        //left and right
        
        if(st[(2*curNode + 1)] >= k)    //decide which subtree we need to choose!
            return findEmptySlot(st,2*curNode + 1,start,mid,k);
        else
            return findEmptySlot(st,2*curNode + 2,mid + 1,end,k - st[(2*curNode + 1)]);
        
    }
    
    
    return -1;  //not in this
        
        
}
vector<int> order(vector<int> &A, vector<int> &B)
{   
    int n = A.size();
    v<pair<int,int>> arr(n);
    for(int i = 0;i<n;i++)
    {
        arr[i].first = A[i];
        arr[i].second = B[i];
    }
    
    sort(arr.begin(),arr.end());    //NLogN
    //making segment tree
    v<int>st(4*n);
    builtTree(st,0,0,n - 1);    //0 based indexing
        
    // return st;
    v<int> res(n);
    for(int i = 0;i<n;i++)
    {
        int pos = findEmptySlot(st,0,0,n-1,arr[i].second + 1);  //find position using segment tree
        res[pos] = arr[i].first;    //insert element into position
    }
    
    return res;
}



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
