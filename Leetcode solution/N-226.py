
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if root==None:
            return None
        if root.left==None and root.right==None:
            return root
        root.left=self.invertTree(root.left)
        root.right=self.invertTree(root.right)
        temp=(root.left)
        (root.left)=(root.right)
        (root.right)=temp
        
        return root
            