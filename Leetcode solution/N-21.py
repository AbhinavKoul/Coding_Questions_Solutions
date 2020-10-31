class ListNode(object):
    def __init__(self, val, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def mergeTwoLists(self, l1, l2):
        newnode=ListNode(0)
        current=newnode
        while l1!=None and l2!=None:
            if l1.val<l2.val:
                prev=l1
                l1=l1.next
                prev.next=None
                current.next=prev
                
                current=current.next
            else:
                prev=l2
                l2=l2.next
                prev.next=None
                current.next=prev
                
                current=current.next
        if l2==None:
            current.next=l1
        else:
            current.next=l2
        newnode=newnode.next
        return newnode