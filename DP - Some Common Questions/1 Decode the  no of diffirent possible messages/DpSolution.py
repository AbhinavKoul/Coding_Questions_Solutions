def numWays_DP(arr,i,dp)->int:
    '''
    Remember to return values always as otherwise it will lead tO None return at line 19
    Time : O(N)
    '''
    #base condittion
    if i == len(arr):
        return 1

    if dp[i] is not None:
        return dp[i]
    
    if arr[i] == 0:
        return 0

    #genersal
    res = numWays_DP(arr,i+1,dp)

    if (int("".join(arr[i:i+2])) <= 26) and (i+2 <= len(arr)):
        res += numWays_DP(arr,i+2,dp)
    
    dp[i] = res
    return res

def dpSol(arr):
    dp = [None]*len(arr)
    i = 0
    return numWays_DP(arr,i,dp)

arr = "11111"
print(dpSol(arr))