class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows==0:
            return []
        if numRows==1:
            return [[1]]
        if numRows==2:
            ans=[[1],[1,1]]
            return ans
        ans=[[1],[1,1]]
        start=ans[1]
        v2=[]
        l=2
        for i in range(numRows-2):
            for j in range(l):
                if (j==0):
                    v2.append(1)
                elif (j==l-1):
                    v2.append(start[j]+start[j-1])
                    v2.append(1)
                else:
                    v2.append(start[j]+start[j-1])                      
            ans.append(v2)
            start=v2
            v2=[]
            l+=1
        return ans