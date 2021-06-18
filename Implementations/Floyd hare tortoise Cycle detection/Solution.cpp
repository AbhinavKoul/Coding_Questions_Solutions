#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define v vector

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    
     ListNode *detectCycle(ListNode *head) {
            
         bool iscycle = false;
         ListNode *slowptr = head, *fastptr = head;
         
         //let hare run fast and tortoise at its normal speed
         while(slowptr && fastptr->next && fastptr)
         {
             slowptr = slowptr->next;
             fastptr = fastptr->next->next;
             
             if(slowptr == fastptr)
             {
                 iscycle = true;
                 break;
             }
         }
         
         if(!iscycle)   // if they never meet
             return nullptr;
         
         // now slow down the tortoise(starts from beggin) 
         // and hare(starts from previous point of intersection)( now when they meet, is point fo cycle begins
         slowptr = head;
         while(slowptr != fastptr)
         {
             slowptr = slowptr->next;
             fastptr = fastptr->next;
         }
         
         return slowptr;
    }
};