class Solution:
    def longestValidParentheses(self, s: str) -> int:
        l=len(s)
        stack=[-1]
        p=0
        maxlen=0
        for i in range(l):
            if s[i]=='(':
                stack.append(i)
            else:
                stack.pop()
                if len(stack)==0:
                    stack.append(i)
                else:
                    l2=len(stack)
                    p=i-stack[l2-1]
                if p>maxlen:
                    maxlen=p
                    
        return maxlen