//https://www.geeksforgeeks.org/maximum-length-of-all-possible-k-equal-length-ropes-generated-by-cutting-n-ropes/#:~:text=After%20the%20above%20combinations%20of,least(K%20%3D%205).
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;
#define v vector
int maximumSize(int a[], int k, int n)
{
    // Stores the left and
    // the right boundaries
    int low = 1;
    int high = *max_element(a, a + n);
 
    // Stores the maximum length
    // of rope possible
    int ans = -1;
 
    // Iterate while low is less
    // than or equal to high
    while (low <= high) {
 
        // Stores the mid value of
        // the range [low, high]
        int mid = low + (high - low) / 2;
 
        // Stores the count of ropes
        // of length mid
        int count = 0;
 
        // Traverse the array arr[]
        for (int c = 0; c < n; c++) {
            count += a[c] / mid;
        }
 
        // If count is at least K
        if (count >= k) {
 
            // Assign mid to ans
            ans = mid;
 
            // Update the value
            // of low
            low = mid + 1;
        }
 
        // Otherwise, update the
        // value of high
        else {
            high = mid - 1;
        }
    }
 
    // Return the value of ans
    return ans;
}