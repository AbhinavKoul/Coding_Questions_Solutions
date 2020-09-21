#include<iostream>
#include<vector>
using namespace std;

int findMin(const vector<int> &A) {
    /*
    Time : O(logN)
    No of times array is rotated is the index position of the min index

    NOTE ===> APPARANTLY SAME CODE IN PYTHON GIVES TIMEOUT ERROR!!
    */
    int low,high,mid,min_index;
    low = 0;
    high = A.size() - 1;
    min_index = 0; // global minima index storage
    
    while(low<=high)
    {
        mid = (low + high)/2;
        if(A[mid]<A[min_index])
        {
            min_index = mid; //updating global minima index
            high = mid - 1; 
        }
        else
            low = mid + 1;
    }
    return A[min_index];
}