# https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
#  ip:        1 
#           /   \ 
#          2     3 
#        /  \ 
#       4    5 
#  op:4 2 5 1 3
class Node():
    def __init__(self,v=0,l=None,r=None):
        self.v=v
        self.r=r
        self.l=l

def inorder(root):
    stk=[]
    curr=root
    while True:
        if curr is not None:
            stk.append(curr)
            curr=curr.l
        elif stk:
            curr=stk.pop()
            #stk.append(curr.right)
            print(curr.v,end=' ')
            curr=curr.r
        else:
            break

root = Node(1) 
root.l = Node(2) 
root.r = Node(3) 
root.l.l = Node(4) 
root.l.r = Node(5)

inorder(root)
