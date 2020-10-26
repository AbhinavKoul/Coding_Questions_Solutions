'''
Returns the max subarray inside the array with its start and end index positions as well
Time : O(N)
Space: O(1)
'''

def kandanesAlgo(arr):
    local_max = 0
    global_max = 0
    slowPtr = fastPtr = 0

    start = end = slowPtr

    for val in arr:
        local_max += val

        if(global_max < local_max):
            global_max = local_max
            end = fastPtr
            start = slowPtr


        if(local_max < 0):
            local_max = 0
            slowPtr += 1
        
        #always incrrement fastptr
        fastPtr += 1 
    
    return (global_max,start,end)

inp = [-2,-3,4,-1,-2,1,5,-3]
print(kandanesAlgo(inp))
