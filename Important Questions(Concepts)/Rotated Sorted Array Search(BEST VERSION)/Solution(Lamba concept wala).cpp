#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define v vector
class Solution {
    /*
    Time = 4ms on leetcode
    */
    public:
        int find_pivot(v<int>&arr,int size)
            {
                int n = size;
                int low,high,mid,min_index = 0;
                low = 0;
                high = n-1;
                while(low<=high)
                {
                    mid = (low + high)/2;
                    if(arr[mid] < arr[min_index])   // iska matlab ki aapka mid min se chota hai to we need to find kinda global min
                    {
                        min_index = mid;
                        high = mid - 1;
                    }
                    else                    // agar min se bada hai to min ko update karne ka matlab nahi, just increment low
                    {
                        low = mid + 1;
                    }

                }

                return min_index;
            }

        int binarySearch(v<int>& arr,int low,int high,int key)  //normal bakwaws
            {
                int mid;
                while(low<=high)
                {
                    mid = (low + high)/2;

                    if(arr[mid] == key)
                        return mid;

                    if(arr[mid] < key)
                        low = mid + 1;
                    else 
                        high = mid - 1;
                }

                return -1;  //if nt found
            }
        int find_key(v<int> &arr,int size,int key,int pivot)
            {

                if(arr[pivot] == key)   
                    return pivot;
                if(key > arr[size - 1])     //to find ki 1st half me hai ya last half me
                    return binarySearch(arr,0,pivot - 1,key);
                 else
                    return binarySearch(arr,pivot+1,size - 1,key);
            }
        int search(vector<int>& arr, int key) {
                int size = arr.size();
                int pivot = find_pivot(arr,size);
                return find_key(arr,size,key,pivot);
           

        }
    };