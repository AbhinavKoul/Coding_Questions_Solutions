/*
USING PAIR AND UNORDERED MAP
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#define ul unordered_map
using namespace std;


int duplicate_element(vector<int> &A)
{
    /*
        TIME : O(N)
        SPACE: O(N)
    */

    ul<int,int> char_set;
    // make dictionary
    for(auto i : A)
        char_set[i]++;
    // extract values from dictionary
    for(pair<int,int> it : char_set)
    {
        if(it.second > 1) 
            return it.first;
    }
}

int main()
{
    vector<int> A = {3, 6, 4, 4,1};
    int res = duplicate_element(A);
    cout<<"HEKKO  ";
    cout<<res;
    return 0;
}