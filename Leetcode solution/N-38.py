class Solution:
    def countAndSay(self, n: int) -> str:
        if n==1:
            return "1"
        elif n==2:
            return "11"
        elif n==3:
            return "21"
        else:
            p=self.countAndSay(n-1)
            p=str(p)
            l=len(p)
            i=0
            ans=""
            while i!=l:
                q=p[i]
                count=0
                while i!=l and q==p[i]:
                    count+=1
                    i+=1
                ans=ans+str(count)+str(q)
            return ans