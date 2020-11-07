class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        l=len(strs)
        if l==0:
            return ""
        if l==1:
            return strs[0]
        le=[]
        same=""
        for i in range(l):
            q=len(strs[i])
            le.append(q)
        p=min(le)
        for i in range(p):
            count=0
            for j in range(l):
                if strs[0][i]!=strs[j][i]:
                    count=1
                    break
            if count==1:
                break
            else:
                same=same+strs[0][i]
        return same