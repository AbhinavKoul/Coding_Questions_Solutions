#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> arr,int low,int high,int key)
{
    /*
    Time : O(logN)
    */
    int mid;
    while(low<=high)
    {
        mid = (low + high)/2;
        if(arr[mid] == key)
            return mid;
        else if(key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1; 
    }
    
    return -1;
}