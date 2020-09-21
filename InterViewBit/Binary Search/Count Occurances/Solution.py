def findCountAndRanfe_MOSTEFFICIENT(A,B):
    '''
    Time : O(logN) ==>still tell me ==> obviosly something wrong is there
    '''
    right = left = -1
    found = False
    
    # binary search for right side
    low = 0
    high = len(A) - 1
    
    while(low<=high):               
        mid = int((low+high)/2)
        
        if(A[mid] == B):
            found = True
            right = mid
            low = mid + 1
        elif(B < A[mid]):
            high = mid - 1
        else:
            low = mid + 1
    
    #binary search for left side
    low = 0
    high = len(A) - 1

    while(low<=high):
        mid = int((low+high)/2)
        
        if(A[mid] == B):
            found = True
            left = mid
            high = mid - 1
        elif(B < A[mid]):
            high = mid - 1
        else:
            low = mid + 1
    
    if(found):
        count = right - left + 1
        return count
    else:
        return 0


def findCount_TimeOut(A, B):
    '''
    O(log N * N) ==>assume : still tell me what is reality
    '''
    is_found = 0
    right = 0
    left = 0
    
    low = 0
    high = len(A) - 1
    
    while(low<=high):
        mid = int((low+high)/2)
        
        #if key found
        if(A[mid] == B):
            found = 1
            right = left = mid
            
            #going towards left
            low_l = low
            high_l = mid - 1
            
            while(low_l < mid):
                mid_l = int((low_l + high_l)/2)
                
                if(A[mid_l] < B):
                    low_l = mid_l + 1
                else:
                    if(low_l == mid_l):
                        left = low_l
                        break
                    else:
                        high_l = mid_l - 1
            
            #going towards right
            low_r = mid + 1
            high_r = high
            
            while(high_r > mid):
                mid_r = int((low_r + high_r)/2)
                
                if(A[mid_r] > B):
                    high_r = mid_r - 1
                else:
                    if(high_r == mid_r):
                        right = high_r
                        break
                    else:
                        low_r = mid_r + 1
            
            break
        
        elif(B < A[mid]):
            high = mid - 1
        else:
            low = mid + 1
                
                    
    count = right - left + 1
    return count


# A = [ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 ]
B = 7
A = [1,1,1,1,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,7,7,7,7,7]
print(findCount_TimeOut(A,B))
