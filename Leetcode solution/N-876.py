class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def middleNode(self, head):
        if head==None:
            return None
        if head.next==None:
            return head
        current=head
        count=0
        while current!=None:
            count+=1
            current=current.next
        if count%2==0:
            count=count//2
        else:
            count=(count-1)//2
        current=head
        for i in range(count):
            prev=current
            current=current.next
        prev.next=None
        return current