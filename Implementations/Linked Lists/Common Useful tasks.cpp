struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
#define LS ListNode

ListNode *reverseLinkedList(ListNode *head) 
{

    if (head->next == nullptr) 
        return head;
    
    ListNode *cur = head, *nextNode = head->next, *tmp;

    while (nextNode != nullptr) 
    {
        tmp = nextNode->next;
        nextNode->next = cur;
        cur = nextNode;
        nextNode = tmp;
    }

    head->next = nextNode;
    return cur;
}

struct ListNode* new_node = new ListNode(carry); // using constructor
        //          OR
        /*
        struct ListNode* new_node =(struct ListNode*) malloc(sizeof(struct ListNode));
        new_node->val = carry;
        new_node->next = nullptr;
        */