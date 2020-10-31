class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        current = head
        count=0
        while current!=None:
            count+=1
            current=current.next
        i=1
        current=head
        ans=0
        while current!=None:
            ans+=(current.val)*2**(count-i)
            i+=1
            current=current.next
        return ans