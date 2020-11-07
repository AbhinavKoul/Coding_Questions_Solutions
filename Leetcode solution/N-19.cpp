class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *curr,*prev;
        int count=0,i=0;
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        curr= dummy;
        while (curr->next!=NULL){
            count+=1;  
            prev=curr;
            curr=curr->next;
        }
        if (n==1 && count==1){
            return NULL;
        }
        if (n==1){
            prev->next=NULL;
            return head;
        }
        else if (n==count){
            curr=dummy->next;
            dummy->next=curr->next;
            return dummy->next;
        }
        else{
        curr=head;
        prev=head;
        for( i=0;i<count-n;i++){
            prev=curr;
            curr=curr->next;       
        }
        prev->next=curr->next;
        return dummy->next;
        }
    }
};