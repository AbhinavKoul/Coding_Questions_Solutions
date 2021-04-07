#include<iostream>
// #include<bits/stdc++.h>
#include<vector>
#include<queue>

#define v vector
using namespace std;

struct ListNode {
   int val;
   ListNode *next;     
   ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode preHead(0), *p = &preHead; //prehead is a new list
    int extra = 0;
    while (l1 || l2 || extra) 
    {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
        extra = sum / 10;
        p->next = new ListNode(sum % 10);
        p = p->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return preHead.next;    //sending new list head address
}
};