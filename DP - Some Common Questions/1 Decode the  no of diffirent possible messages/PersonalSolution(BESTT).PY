class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        res = [None]*(n+1);
        res[n] = 1
        
        if(s[n-1] == '0'):
            res[n-1] = 0
        else:
            res[n-1] = 1
            
        for i in range(n-2,-1,-1):
            if s[i] == '0':
                res[i] = 0
            elif int(s[i:i+2]) <=26:
                res[i] = res[i+1] + res[i+2]
            else:
                res[i] = res[i+1]
        
        return res[0]
        