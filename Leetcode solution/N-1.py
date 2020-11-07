class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d={}
        for index,value in enumerate(nums):
            if target-value in d:
                return (d[target-value],index)
            else:
                d[value]=index