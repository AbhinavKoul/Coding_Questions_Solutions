#include<iostream>
// #include<bits/stdc++.h>
#include<vector>
#include<queue>

#define v vector
using namespace std;
/**
 * @paragraph Fenwick Trees Idea 
 * 1. Similar to Segment tree, but with better time and space complexity
 *    due to the usage of bits in determining which range does a particular index stores.
 *    (BASICALLY it is like each index keeps track of 2^LeastSignificantBit elements below it)
 * 
 * 2. eg. array index 15, will have responsibility of 1111 --> only 1 index ie itself
 *    THIS IS FOR ALL ODD INDEXES as their lowest bit is always 1
 * 
 * 3. eg. index = 14 ==> 01110 --> has responsiobility of 2 nodes (10) ie 13 and 14
 * 4. eg  index = 16 --> 10000 --> responsibility of 16 nodes ie from 1 till 16 --> inclusive
 * 
 * 5. This overlap makes sure that we will get any sum from 1 till any index, we just need to trace the powers of 2
 * 
 * @details Range Function (Sum till certain index)
 * 1. eg [1 .. 15] == 15 + 14 + 12 + 8 
 *      
 *   Now going down the ladder till one, we need to remove the elements till it is responsible for.
 *   ie. removing the LSB from the number x
 *   
 *   rightmost set bit == no of elements responsible = (x & x`)
 *   now removing these elements = (x - (x & x`))
 * 
 *   keep doing this till you reach 1.
 * 
 * 2. Since this keeps on going till no of bits in worst case. eg(1111) == log(number) == ceil(log(15)) == 4
 * 
 * @details Update Function
 * 1. eg update(1,3) --> update 1st index and add 3 to current (ie. diffirence is 3)
 * 
 *     == 1 + 2 + 4 + 8 + 16
 *       (1) (2) (4) (8)          <----- responsibilities
 *     Now here we need to go up the ladder and add this delta to all the elements which is responsible for this index
 *     ie. we need to go up by the number of elements the currrent index is responsible for to reach another index which
 *         is responsible for current
 * 
 *     --> increment the number of responsibilities to current
 * 
 *     adding responsible elements = (x + (x & x`))
 *     keep doing this till you do not exceed max array size
 * 
 * 2. eg 2 ==> 5 --> 5 + 6 + 8 + 16
 *                  (1) (2) (8)      <----- responsibilities
 * 
 * 3. eg 3 ==> 7 --> 7 + 8 + 16
 *                  (1) (8)          <----- responsibilities
 * 
 * 4. eg 4 ==> 9 --> 9 + 10 + 12 + 16
 *                  (1)  (2) (4)     <----- responsibilities
 * 
 * */
int sum(const v<int> &bit,int idx)
{
    int sum = 0;
    while(idx > 0)
    {
        sum += bit[idx];

        //going down the path
        idx -= (idx & (-idx));
    }

    return sum;
}
int rangeSum(const v<int> &bit,int left,int right)
{
    int n = bit.size();
    if(left < 1 || right >=n || right < left)
    {
        cout<<"invalid range";
        return -1;
    }

    return sum(bit,right) - sum(bit,left - 1);  //cause we need answer inclusive range
}
void update_bit(const v<int> &arr,v<int>&bit,int idx,int val,const int n)
{
    while(idx<n)
    {
        bit[idx] += val;

        //going up the ladder
        idx += (idx & (-idx));
    }
}
void update(v<int> &arr,v<int>&bit,int pos,int newVal)
{
    int n = arr.size();
    if(pos < 1 || pos >= n)
    {
        cout<<"invalid";
        return;
    }

    int diff = newVal - arr[pos];
    arr[pos] = newVal;
    update_bit(arr,bit,pos,diff,n);   
}
v<int> builtTree(const v<int>&arr)
{
    int n = arr.size();
    v<int> bit(n,0);
    
    //1 based indexing
    for(int i = 1;i<n;i++)
    {
        update_bit(arr,bit,i,arr[i],n);
    }

    return bit;
}
int main()
{
    v<int> arr = {0,2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};    //(12 elements)
    int n = arr.size();
    

    //built tree
    v<int> bit = builtTree(arr);

    cout<<"hellooooo \n : ";
    for(auto i : bit)
        cout<<i<<" ";

    cout<<"\n range sum : [1...6] ==> "<<sum(bit,6); 
    cout<<"\n range sum : [2...6] ==> "<<rangeSum(bit,2,6);
    cout<<"\n range sum : [3...6] ==> "<<rangeSum(bit,3,6);
    cout<<"\n range sum : [6...6] ==> "<<rangeSum(bit,6,6);
    update(arr,bit,4,9);
    cout<<"\n updating 4th element to 9 from 3(increment by 6) ........\n New range sum [1..6] : "<<sum(bit,6);    
    
    update(arr,bit,4,5);
    cout<<"\n updating 4th element to 5 from 9(decrement by 4) ........\n New range sum [1..6] : "<<sum(bit,6);    

    return 0;
}