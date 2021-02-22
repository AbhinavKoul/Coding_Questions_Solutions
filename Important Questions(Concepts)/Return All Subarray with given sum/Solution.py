def subArraySum(arr, n, s): 
    #Your code here
    mapping = {}
    result = []
    cumSum = 0;
    for i in range(len(arr)):
        cumSum += arr[i]
        mapping[cumSum] = i
    
    mappingList = list(sorted(mapping))
    
    for i in range(len(mappingList)):
        search = mappingList[i] - sf
        if search in mapping:
            if(i != mapping[search]):
                result.append(i)
                result.append(mapping[search])
            
    return result