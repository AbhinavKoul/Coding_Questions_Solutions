def numWays(arr,i):
    #base condition
    if i >= len(arr):
        return 1

    if arr[i] == '0':
        return 0
    
    #general case
    res = numWays(arr,i+1)

    if (int("".join(arr[i:i+2])) <= 26) and (i+2 <= len(arr)):
        res += numWays(arr,i+2)
    
    return res


arr = "012134"

print(numWays(arr,0))

