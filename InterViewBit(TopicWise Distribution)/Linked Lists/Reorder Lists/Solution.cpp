#include<iostream>
#include<vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
#define LS ListNode
ListNode* reorderList(ListNode* head) {
    /*
    Time : O(N^2)
    Spce : O(1)
    */
    if(head == nullptr || head->next == nullptr)
        return head;
    
    LS *high,*prev_high,*low;
    
    low = prev_high = head;
    high = low->next;
    
    while(high->next!=nullptr)
    {
        high = high->next;
        prev_high = prev_high->next;
    }
    
    int flip = 0;
    while(high!=low || prev_high!=low)
    {
        if(flip!=0)
        {
            LS *temp;
            temp = prev_high;
            prev_high = high;
            high = temp;
        }
        high->next = low->next;
        low->next = high;
        
        //updationg
        low = low->next->next;
        while(high->next!=prev_high)
            high = high->next;
        
        prev_high->next = nullptr;
        flip++;
    }
    
    return head;
}

ListNode* reorderList(ListNode* A)
{
    /*
    Time : O(N)
    Space: O(N)

    Using extra vector to keep trac of all addresses
    */
    vector<ListNode*>arr; 
    ListNode* ptr = A;

    while(ptr!=NULL)
    {
        arr.push_back(ptr);
        ptr = ptr->next;
    }
    
    int n = arr.size();
    int i=0;
    
    for (; i<n/2; i++){
        arr[i]->next = arr[n-i-1];
        
        if (n-i-1 == i+1) 
            arr[n-i-1]->next = NULL;
        else 
            arr[n-i-1]->next = arr[i+1];
    }
    arr[i]->next = NULL;
    return A;
}
class Solution {
    /*
    Time : O(N)
    Space: O(1)
    
    1. Find middle element
    2. reverse 2nd list
    3. merge two
    */
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;

        ListNode* head = l1;    // head of the list to return
        l1 = l1->next;

        ListNode* p = head;     // pointer to form new list
        // A boolean to track which list we need to extract from. 
        // We alternate between first and second list. 
        bool curListNum = true;

        while(l1 && l2){
            if(curListNum == false) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
            curListNum = !curListNum;
        }

        // add the rest of the tail, done!
        if (l1) {
            p->next = l1;
        } else {
            p->next = l2;
        }

        return head;
    }

    ListNode *reverseLinkedList(ListNode *head) {
        if (head->next == nullptr) return head;
        ListNode *cur = head, *nextNode = head->next, *tmp;

        while (nextNode != nullptr) {
            tmp = nextNode->next;
            nextNode->next = cur;
            cur = nextNode;
            nextNode = tmp;
        }

        head->next = nextNode;
        return cur;
    }

    ListNode* reorderList(ListNode *head) {
        if(head == nullptr || head->next == nullptr || head->next->next==nullptr)
            return head;

        //find the middle of the list, and split into two lists.    
        ListNode *slow = head,*fast = head;
        while(slow != nullptr && fast != nullptr && fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *mid = slow->next;
        slow->next = nullptr;

        //reverse from the middle to the end
        ListNode* secondHalfReversed = reverseLinkedList(mid);

        //merge these two list
        return head = mergeTwoLists(head, secondHalfReversed);
    }
};