// C++ program to demonstrate default behaviour of
// sort() in STL.
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
#define v vector
int main()
{
    v<int> arr = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    /*Here we take two parameters, the beginning of the
    array and the length n upto which we want the array to
    be sorted*/
    sort(arr.begin(),arr.end()); // sort(arr, arr + n, greater<int>()); -> sORTS IN DECENDING ORDER
 
    cout << "\nArray after sorting using "
            "default sort is : \n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
 
    return 0;
}

/*
USER DEFINED COMPARE FN

This “comparator” function returns a value;
convertible to bool, which basically tells us 
whether the passed “first” argument should be placed 
before the passed “second” argument or not. 

*/