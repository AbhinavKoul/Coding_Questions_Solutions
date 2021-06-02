#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define v vector
//LINK : https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1#

class Solution {
  public:
  int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr, arr+n);
        for (int i = 0; i < n; ++i)     //1st choice we do==> add all
            arr[i]+=k;
        
        int mini = arr[0], maxi=arr[n-1], ans = maxi-mini;  //calc basic ans 

        // now we do element by element on other side, and update the new max min scenario in that case and result in answer

        for (int i = n-1; i >=0 ; --i) 
        {
            arr[i]-= 2*k;       //reduce this element

            if (arr[i]<0) 
                break;

            //for the 1st element(ir all are reduced --> max will be the last element only)
            //for other elements --> since array is sorted, thus max will be max of just preceding elemt or the max
            i > 0 ? maxi = max(arr[n-1], arr[i-1]) : maxi = arr[n-1];

            // min is easy--> just check current one with 1st one
            mini = min(arr[0], arr[i]);

            //keep updating answers
            ans = min(ans, maxi-mini);
        }
        return ans;
    }
};