#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// BRUTE FORCE
int search(vector<int>& nums, int target) {
    // Time : O(NlogN) ==> can do in n as well
        
        int rotated = abs(distance(nums.begin(),min_element(nums.begin(),nums.end())));
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i] == target)
                return (i + rotated)%n;
        }
        
        return -1;
        
}



//helper fns
int findPivot(vector<int> A) {
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
    return min_index;
}

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
int searchRotated(const vector<int> &arr, int key) {
    /*
    Time : O(log N)
    1. finding pivot ==> O(logN)
    2. Searching ==> O(logN)
    */
   int pivot = findPivot(arr); 
   int n = arr.size();
    // If we didn't find a pivot, 
    // then array is not rotated at all 
    if (pivot == 0) 
        return binarySearch(arr, 0, n - 1, key); 
  
    // If we found a pivot, then first compare with pivot 
    // and then search in two subarrays around pivot 
    if (arr[pivot] == key) 
        return pivot; 

    // if avialable in upper side array
    if (arr[0] <= key) 
        return binarySearch(arr, 0, pivot - 1, key); 
    
    // otherwise lower side array
    return binarySearch(arr, pivot + 1, n - 1, key); 

}

int main()
{
    vector<int> arr = { 186, 192, 193, 202, 204, 2, 3, 6, 10, 11, 12, 17, 21, 28, 29, 30, 31, 32, 37, 38, 39, 40, 41, 47, 49, 50, 51, 52, 55, 57, 58, 59, 60, 65, 67, 68, 71, 72, 74, 77, 78, 80, 82, 83, 88, 89, 90, 94, 100, 107, 108, 109, 111, 112, 114, 115, 116, 118, 119, 121, 123, 124, 126, 129, 133, 134, 135, 137, 138, 144, 147, 148, 150, 151, 154, 156, 159, 161, 163, 165, 166, 167, 168, 169, 174, 178, 180, 182, 183, 185};
    int index = searchRotated(arr,202);
    cout<<"INDEX IS AT :  "<<index;

}

