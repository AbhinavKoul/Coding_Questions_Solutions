class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        if head==None:
            return None
        if head.next==None and head.val==val:
            return None
        if head.next==None and head.val!=val:
            return head
        n=ListNode(-1)
        n.next=head
        head=n
        prev=head
        current=head.next
        while current!=None:
            if current.val==val:
                prev.next=current.next
                current=current.next
            else:
                prev=current
                current=current.next
        return head.next