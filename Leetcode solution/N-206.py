class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = None
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head==None:
            return None
        if head.next==None:
            return head
        current=head
        temp=head.next
        final=temp.next
        current.next=None
        while temp.next!=None:
            temp.next=None
            temp.next=current
            current=temp
            temp=final
            final=final.next
        temp.next=current
        head=temp
        return head