#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
#define v vector
#define um unordered_map
#define mod 1000000007
#define ll long long int
using namespace std;

//O(NLOGN)
int maxp3(vector<int> &A) {
    int n=A.size();
    if(n<3) return 0;
        
    sort(A.begin(),A.end());

    int back=A[n-1]*A[n-2]*A[n-3];
    int front=A[0]*A[1]*A[n-1];

    return max(front,back);
}

//O(N)
// we need 5 variables
/*
    max 3 elements
    minimum 2 elements

    answer would be either
    --> prod of max 3 elements
    --> if negative
        ==> negative 2 elements and max positive element
*/
int maxp3(vector<int> &arr) {
    int n=arr.size();
    // if size is less than 3, no triplet exists
    if (n < 3)
        return -1;
 
    // Initialize Maximum, second maximum and third
    // maximum element
    int maxA = INT_MIN, maxB = INT_MIN, maxC = INT_MIN;
 
    // Initialize Minimum and second mimimum element
    int minA = INT_MAX, minB = INT_MAX;
 
    for (int i = 0; i < n; i++)
    {
        // Update Maximum, second maximum and third
        // maximum element
        if (arr[i] > maxA)
        {
            maxC = maxB;
            maxB = maxA;
            maxA = arr[i];
        }
 
        // Update second maximum and third maximum element
        else if (arr[i] > maxB)
        {
            maxC = maxB;
            maxB = arr[i];
        }
 
        // Update third maximum element
        else if (arr[i] > maxC)
            maxC = arr[i];
 
        // Update Minimum and second mimimum element
        if (arr[i] < minA)
        {
            minB = minA;
            minA = arr[i];
        }
 
        // Update second mimimum element
        else if(arr[i] < minB)
            minB = arr[i];
    }
 
    return max(minA * minB * maxA,
               maxA * maxB * maxC);
}

