

// Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode *next;     
   ListNode(int x) : val(x), next(nullptr) {}
 };


ListNode* mergeTwoLists(ListNode* A, ListNode* B) 
{
    if(A==nullptr)
        return B;
    if(B==nullptr)
        return A;
    ListNode* ans=nullptr;
    
    if(A->val < B->val)
    {
        ans=A;
        ans->next=mergeTwoLists(A->next,B);
    }
    else
    {
        ans=B;
        ans->next=mergeTwoLists(A,B->next);
    }
    return ans;
}

ListNode* sortList(ListNode* A) 
{
    if(A==nullptr||A->next==nullptr)
        return A;
    ListNode* slow=A;
    ListNode* temp=A;
    ListNode* fast=A;
    
    while(fast!=nullptr && fast->next!=nullptr)
    {
        temp = slow;
        slow = slow->next;
        fast=fast->next->next;
    }
    
    temp->next = nullptr;
    ListNode* LS = sortList(A);
    ListNode* LR = sortList(slow);
    
    return mergeTwoLists(LS,LR);
}
