#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int SingleNumber_BEST(vector<int> arr)
{
    /*
    ----------------------------------------------------BEST SPACE AND TIME-----------------------------------------------
    Time : O(N)                                             ♡♡♡♡♡♡♡♡
    Space: O(3)                                               ♡♡♡♡♡
                                                               ♡♡♡
    THIS APPROACH JUST MADE ME LOVE MATHS AGAIN! ♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡
    hello  my old friend, i know i took a year off but you are always in my heart!
    */
    int n = arr.size();
    int ones = 0,twos = 0,threes = 0;

    for(int i=0; i<n; i++)
    {
        // set twos if already the same bits are set in ones
        twos |= ones & arr[i];
        // set ones using property of XOR
        ones ^= arr[i];
        // set three if already set in ones and twos
        threes = ones & twos;

        // if three bit is set, clear bit from ones and twos
        ones &= ~threes;
        twos &= ~threes;
    }

    return ones;
}

int SingleNumer_Average(vector<int> arr)
{
    /*
    ----------------------------------------------------AVERAGE SPACE AND TIME-----------------------------------------------
    Time : O(32N)
    Space: O(32)
    */
    int n = arr.size();
    static int count[32];   // to make 0 by default

    int result = 0;     // set all 32 bits to 0 initially

    // check bit by bit from 1st to 32nd
    for(int i = 0; i<32; i++)
    {
        for(int j = 0; j<n; j++)    // transverse full array
            if(arr[j] & (1<<i)) // if bit set at that index
                count[i]++; // increment count at index
        
        result |= ((count[i]%3)<<i);    //will tell value(all are 3 or 1) ==> will result in 1 or 0

        // if not 3 times, then at that index set value!!
    }
}

int SingleNumber_worse_Naive(vector<int> arr)
{
    /*
    Time : O(N)
    Space: O(N)

    Naive bachhe wala approach for anything
    */
    int n = arr.size();
    unordered_map<int,int> char_map;

    for(int i : arr)
        char_map[i]++;
    
    for(int i = 0;i<n;i++)
    {
        if(char_map[arr[i]] == 1)
            return arr[i];
    }
}

