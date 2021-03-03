def shiftTableCreation(substr:str)->dict:
    m = len(substr)
    shift_table = {i:m for i in "ABCDEFGHIFKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"}
    
    for i in range(0,m):
        shift_table[substr[i]] = m - 1 - i

    return shift_table

def string_match(string:str,substr:str)->int:
    len_string = len(string)
    len_substr = len(substr)

    shift_table = shiftTableCreation(substr)
    #find 1st index to check
    i = len_substr-1

    while(i<len_string):
        k = 0
        while((k<=len_substr-1) and (string[i-k]==substr[len_substr-1-k])):
            k += 1
        
        if(k == len_substr):
            return (i - len_substr + 1) # return position of matched string
        else:
            i = i + shift_table[string[i]]
    
    return -1 #element not found

print(shiftTableCreation("abc"))