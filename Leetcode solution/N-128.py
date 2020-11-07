class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        l=len(nums)
        highest=0
        numset=set(nums)
        for i in range(l):
            if nums[i]-1 not in numset:
                num=nums[i]
                current=1
                while num+1 in numset:
                    num=num+1
                    current+=1
                highest=max(current,highest)
        return highest