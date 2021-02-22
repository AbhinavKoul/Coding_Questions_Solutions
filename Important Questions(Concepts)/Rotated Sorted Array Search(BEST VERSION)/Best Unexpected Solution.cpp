#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define v vector

class Solution {
    public:
        int search(vector<int>& arr, int key) {
            /*
            Time = 0ms on leetcode
            */
              auto it = find(arr.begin(),arr.end(),key);  //O(logN)
              if(it!=arr.end())
                   return (it - arr.begin());
              else
                    return -1;
        }
    };