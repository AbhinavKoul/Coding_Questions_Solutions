def rearrangeArrayInPlace(arr:list)->list:
    n = len(arr)
    for i in range(0,n):
        arr[i] += (int(arr[arr[i]]%n))*n
    
    for i in range(0,n):
        arr[i] = int(arr[i]/n)
    
    return arr

array = [1,1,3,4,3,5]
ans = rearrangeArrayInPlace(array)
print(ans)