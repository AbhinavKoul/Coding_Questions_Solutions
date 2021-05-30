/*
https://www.geeksforgeeks.org/merge-k-sorted-linked-lists/

In this post, Divide and Conquer approach is discussed. This approach doesn’t require extra space for heap and works in O(nk Log k)
It is known that merging of two linked lists can be done in O(n) time and O(n) space. 

The idea is to pair up K lists and merge each pair in linear time using O(n) space.
After the first cycle, K/2 lists are left each of size 2*N. After the second cycle, K/4 lists are left each of size 4*N and so on.
Repeat the procedure until we have only one list left.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define v vector

vector<int> merge(vector<int>& a, vector<int>& b) {
    vector<int> temp;
    int i = 0, j = 0;
    if (a.size() == 0) return b;
    if (b.size() == 0) return a;

    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            temp.push_back(a[i]);
            i++;
        } else {
            temp.push_back(b[j]);
            j++;
        }
    }
    while (i < a.size()) {
        temp.push_back(a[i]);
        i++;
    }
    while (j < b.size()) {
        temp.push_back(b[j]);
        j++;
    }

    return temp;
}

vector<int> helper(vector<vector<int>>& lists, int st, int end) {
    if (st == end) return lists[st];
    int mid = st + (end - st) / 2;
    vector<int> a = helper(lists, st, mid);
    vector<int> b = helper(lists, mid + 1, end);
    return merge(a, b);
}

vector<int> solve(vector<vector<int>>& lists) {
    int k = lists.size();
    if (k == 0) return {};

    return helper(lists, 0, k - 1);
}