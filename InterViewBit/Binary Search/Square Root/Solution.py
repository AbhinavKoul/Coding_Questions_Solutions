def sqrt(A):
    '''
    PYTHON RELIEVES THE STRESS OF OVERFLOW!!!!!!!!!
    TIME : O(logN)
    due to monotonours incresing fn, we can use binary search approah
    '''
    if A in range(1,4):
        return 1
    
    low = 0
    high = A
    ans = 0
    while(low<=high):
        # as python doesnt do intergral division ==> need to use int fn
        mid = int((low+high)/2)
        if (mid*mid)>A:
            high = mid - 1
        else:
            low = mid + 1
            ans = mid
    return ans

print(sqrt(2147483647))