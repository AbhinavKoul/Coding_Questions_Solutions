class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        l1=len(S)
        l2=len(T)
        stack=[]
        for i in range(l1):
            if S[i]!="#":
                stack.append(S[i])
            else:
                x=len(stack)
                if x==0:
                    continue
                if x!=0 and stack[x-1]!="#":
                    stack.pop(x-1)
        l=len(stack)
        s=""
        for i in range(l):
            s=s+stack[i]
        stack=[]
        for i in range(l2):
            if T[i]!="#":
                stack.append(T[i])
            else:
                x=len(stack)
                if x==0:
                    continue
                elif x!=0 and stack[x-1]!="#":
                    stack.pop(x-1)
        l=len(stack)
        p=""
        for i in range(l):
            p=p+stack[i]
        if s==p:
            return True
        else:
            return False
        