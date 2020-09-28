

// Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode *next;     
   ListNode(int x) : val(x), next(nullptr) {}
 };
 
ListNode* addTwoNumbers(ListNode* A, ListNode* B) {
    
    // store result in LList B;
    
    ListNode *currA = A, *currB = B, *prevB;
    
    int carry = 0;
    
    while(currA!= && currB!=nullptr)
    {
        
        prevB = currB;
        
        int a = currA->val;
        int b = currB->val;
    
        currB->val = (a+b+carry)%10;
        carry = (a+b+carry)/10;
        
        
        currA = currA->next;
        currB = currB->next;
        
    }
    // if LList B is short
    
    if(currB == nullptr && currA!=nullptr){
        
        prevB->next = currA;
    }
    
    currB = prevB->next;
    // for both A is hsort and B is short    
    while(currB!=nullptr){
    
        prevB = currB;
        int r = currB->val;
        
        currB->val = (r+carry)%10;
        carry = (r+carry)/10;
        
        currB= currB->next;
    }
    // case if a new element needs to be addded
    if(carry!=0){
        
        struct ListNode* new_node =(struct ListNode*) malloc(sizeof(struct ListNode));
        new_node->val = carry;
        new_node->next = nullptr;
        
        prevB->next = new_node;
        
    }
    
    return B;
}
