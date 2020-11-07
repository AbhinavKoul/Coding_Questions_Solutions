class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        char=[]
        d={}
        for index,value in enumerate(strs):
            for i in range(26):
                char.append(0)
            l=len(value)
            s=""
            for j in range(l):
                char[ord(value[j])-97]+=1
            for j in range(26):
                if char[j]>=1:
                    s=s+(char[j]*chr(j+97))
            if s in d:
                d[s].append(value)
            else:
                d[s]=[value]
            char=[]
            a=[]
        for index,values in enumerate(d):
            a.append(d[values])
        return a
                    