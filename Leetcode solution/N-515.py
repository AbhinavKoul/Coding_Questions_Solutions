class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def largestValues(self, root: TreeNode):
        level=0
        ans=[]
        if root==None:
            return []
        ans.append(root.val)
        self.re(root,level,ans)
        return ans
        
    def re(self,root,level,ans):
        if root==None:
            return
        if level==0:
            ans[0]=root.val
        elif level==len(ans):
            ans.append(root.val)
        else:
            ans[level]= max(root.val,ans[level])
        self.re(root.left,level+1,ans)
        self.re(root.right,level+1,ans)