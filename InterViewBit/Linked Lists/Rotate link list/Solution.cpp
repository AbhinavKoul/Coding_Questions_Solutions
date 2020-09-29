#include<iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x),next(nullptr) {}
};

Node* rotateRight(Node *head,int k)
{
    //if list has 0 or 1 elements
    if(head == nullptr || head->next == nullptr)
        return head;
    
    Node* ptr = head;
    //make ptr as last element and count elements in list
    int count = 1;
    while(ptr->next != nullptr)
    {
        count++;
        ptr = ptr->next;
    }
    //make circular list by linking it with head
    ptr->next = head;

    //calculate shifting (shifting left k times == shifting right count - k times)
    // remember that k>count

    int shift = count - (k%count);

    while (shift)
    {
        head = head->next;
        ptr = ptr->next;
        shift--;
    }

    //make last element as end
    ptr->next = nullptr;

    return head;
}
