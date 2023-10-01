from itertools import chain, combinations


def and_list(nums:list)->int:
    result = nums[0] if nums else 0
    
    for num in nums[1:]:
        result &= num
        
    return result



def xor_list(nums:list)->int:
    result = nums[0] if nums else 0
    
    for num in nums[1:]:
        result ^= num
    
    return result

def powerset(L:list):
    return [L[i:i+j] for i in range(0,len(L)) for j in range(1,len(L)-i+1)]

def function(nums:list)->int:
    n = len(nums)
    twoList = list(powerset(nums))
    print(twoList)
    xorlist = []
    for i in twoList:
        xorlist.append(xor_list(i))
    
    
    return and_list(xorlist)



function([3,5,1])