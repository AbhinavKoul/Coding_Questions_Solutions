class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* current;
        ListNode* prev;
        if (head==nullptr)
            return nullptr;
        if (head->next==nullptr){
            return head;
        }
        prev=head;
        current=head->next;
        int temp;
        while (current!=nullptr){
            temp=prev->val;
            prev->val=current->val;
            current->val=temp;
            
            prev=current->next;
            if (prev==nullptr){
                break;
            }
            current=prev->next;
        }
        return head;   
    }
};