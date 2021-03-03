# Python program to compute sum of pairwise bit differences(ie HAMMING DISTANCE) 
  
def sumBitDifferences(arr,n): 
    '''
    Time : O(N)
    '''
  
    ans = 0  # Initialize result 
  
    # traverse over all bits of int(since 4 Bytes ==> 8*4 = 32 bits)
    for i in range(0, 32): 
      
        # count number of elements with i'th bit set 
        count = 0
        #transverse over all the elements in the list
        for j in range(0,n): 
            #check if ith bit set?
            if ( (arr[j] & (1 << i)) ): 
                count+=1
  
        # Add "count * (n - count) * 2" to the answer 
        # eg 4 elements have set and 5 have not set, thus total diff = 1+...(5*4)times = 20+20 (as reverse also same)
        ans += (count * (n - count) * 2); 
      
    return ans 
  
# Driver prorgram 
arr = [1, 3, 5] 
n = len(arr ) 
print(sumBitDifferences(arr, n)) 