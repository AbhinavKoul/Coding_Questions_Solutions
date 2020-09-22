#include<iostream>
#include<vector>
using namespace std;
int findSingleOccuranceNumber(vector<int> arr)
{
    /*
    Time : O(N)
    Space: O(1)  ==> this leads to innovation!!!!!
    */
    int result = 0;

    /* 
    utilizing associative property of XOR!
    Since all other occur 2 times thus will result in 2 1's == 0 and then element which occurs once will result in 1 '1' ie
    ie.
    A^B^C = A^C^B
    0^B = B
    ie.
    A^A^B = B
    */
    for(auto i : arr)
        result ^= i;
    
    return result;
}


int main()
{
    vector<int> arr = {1,1,4,5,6,5,8,4,6};
    auto result = findSingleOccuranceNumber(arr);
    cout<<"RESULT :  "<<result; 
}