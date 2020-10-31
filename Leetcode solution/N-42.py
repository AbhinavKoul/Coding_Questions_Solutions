class Solution:
    def trap(self, height: List[int]) -> int:
        i=0
        j=0
        farea=0
        l=len(height)
        if l==0:
            return 0
        index=[]
        while j!=l-1:
            p=height[j]
            while p>height[i+1]:
                i+=1
                if i==l-1:
                    i=j+height[j+1:l].index(max(height[j+1:l]))
                    break
            if i-j>0:
                index.append([j,i+1])
                j=i+1
                i+=1
            else:
                j+=1
                i+=1
        l2=len(index)
        for i in range(l2):
            p1=index[i][0]
            p2=index[i][1]
            h=min(height[p1],height[p2])
            w=p2-p1-1
            area=h*w
            for j in range(p1+1,p2):
                area=area-height[j]
            farea=farea+area
        return farea