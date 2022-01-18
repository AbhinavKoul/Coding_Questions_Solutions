#include <stdio.h>
#include <stdbool.h>
#include <iostream>
#include<vector>
#include<algorithm>
#define ll long long

#define v vector
using namespace std;
long long count_combination(v<ll> arr)
{
    sort(arr.begin(),arr.end());
    int idx = -1;    // the left most index which will always contain -1 and no possibility of having postitive value
    for(int i = 0;i<arr.size() - 1;i++)
    {
        if(2*arr[i] >= arr[i+1])   //only one way ie. it will be saved in B ==> thus we can easily assume that no of ways in last lane would not have 'a' part
        {
            arr[i+1] += arr[i];
        }
        else
        {
             idx = i;
             arr[i+1] += arr[i];
        }      
    }

    return arr.size() - idx - 1;
}

int main()
{
    v<ll> arrr= {9,6,7,3};

    cout<<"hello "<<count_combination(arrr);
        return 0;
}