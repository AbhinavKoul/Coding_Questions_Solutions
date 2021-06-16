#include<iostream>
// #include<bits/stdc++.h>
#include<vector>
#include<queue>

#define v vector
using namespace std;

//o based indexing
void builtTree(v<int>&st,const v<int>& arr,int curNode,int start,int end) //O(N)
{
    //if leaf node
    if(start == end)
    {
        st[curNode] = arr[start];  //since all leaf nodes are intially open
    }
    else
    {
        int mid = (start + end)/2;
        
        builtTree(st,arr,2*curNode + 1,start,mid);
        builtTree(st,arr,2*curNode + 2,mid+1,end);
        
        st[curNode] = st[(2*curNode + 1)] + st[(2*curNode + 2)];
    }
}

int getSumUtil(const v<int>&st,int curNode,int curLeft,int curRight,int left,int right)
{
    //total overlap

    if(curLeft >= left && curRight <=right)
        return st[curNode];

    //no overlap
    if(curRight < left || curLeft > right)
        return 0;

    //partial overlap

    int mid = (curLeft + curRight)/2;

    return getSumUtil(st,2*curNode + 1,curLeft,mid,left,right) + getSumUtil(st,2*curNode+2,mid+1,curRight,left,right);
}

/*
n : total no of elements in arr
st: segment tree
left:
right:  Our bound where we want to find the sum
*/
int getSum(const v<int>&st,int n,int left,int right)
{
    //filter wrong queries out
    if(left < 0 || right > n-1 || right < left)
    {
        cout<<"InVALID INPUTS";
        return -1;  
    }

    return getSumUtil(st,0,0,n-1,left,right);   //0 based indexing
}
//--------------------------------------------------------- UPDATION ---------------------------------------------------------

void updateUtil(v<int>&st,int curNode,int curLeft,int curRight,int pos,int diff)
{
    //not in range
    if(pos < curLeft || pos > curRight)
        return;

    //insidee rNGE
    st[curNode] += diff;

    //if not leaf node, we need to goto left and right subtree both and update
    if(curLeft != curRight)
    {
        int mid = (curLeft + curRight)/2;
        
        //left
        updateUtil(st,2*curNode  + 1,curLeft,mid,pos,diff);
        //right
        updateUtil(st,2*curNode + 2,mid+ 1,curRight,pos,diff);
    }   
}

/*
arr : our original array
st : segment tree
n : arr size
pos: positon of arr where we wanna update
val : what is the new value we wanna enter
*/
void update(v<int> & arr,v<int> &st,int n,int pos,int val)
{
    //invalid pos
    if(pos < 0 || pos > n-1)
    {
        cout<<"Invalid";
        return;
    }

    int diff = val - arr[pos];
    updateUtil(st,0,0,n-1,pos,diff);
}
int main()
{
    v<int> arr = {1,2,5,6,7,9};
    int n = arr.size();

    v<int> st(4*n);

    //built tree
    builtTree(st,arr,0,0,n-1);  //0 based indexing

    cout<<"Segment Tree elements : ";
    for(auto i :st)
        cout<<i<<" ";

    cout<<endl;

    cout<<"\n Sum between indexes [2,4] ie position [3,5] : "<< getSum(st,n,2,4)<<" and [1,4]: "<<getSum(st,n,1,4);

    cout<<"\n updating value 6 to 14 in arr ----> ";

    update(arr,st,n,3,14);
    cout<<"\n new segment tree becomes : ";
    for(auto i :st)
        cout<<i<<" ";
    
    cout<<"\n New Sum after Updation between indexes [2,4] ie position [3,5] : "<< getSum(st,n,2,4)<<" and [1,4]: "<<getSum(st,n,1,4);

}