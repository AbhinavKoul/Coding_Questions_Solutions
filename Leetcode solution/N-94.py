class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = None
        self.right = None
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        stack=[]
        ans=[]
        curr=root
        while curr!=None or len(stack)!=0:
            while curr!=None:
                stack.append(curr)
                curr=curr.left
            curr=stack.pop()
            ans.append(curr.val)
            curr=curr.right
        return ans