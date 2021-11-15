

// Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode *next;     
   ListNode(int x) : val(x), next(nullptr) {}
 };

ListNode* deleteDuplicates(ListNode* A) {
    ListNode *i,*j;
    i = A;
    j = A->next;
    
    while(j!=nullptr)
    {
            if((i->val) == (j->val))
            {    
                if(j->next == nullptr)
                    i->next = nullptr;         // very very important!!!!
                    
                j = j->next;
            }
            else
            {
                i->next = j;
                i = i->next;
                j = j->next;
            }
    }
    return A;
}
