class Solution:
    def twoSum(self, nums: List[int], target: in t) -> List[int]:
        d={}
        for index,value in enumerate(nums):
            if target-value in d:
                return (d[target-value],index)
            else:
                d[value]=index