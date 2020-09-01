def checkPalin(arr1:str,arr2:str)->bool:
    '''
    Time Complex : O(n) where n is the length of string
    Space Complex : O(n) 

    Assumes both strings are of equal length and we are not searching for subscript
    '''
    if(len(arr1)!= len(arr2)):
        return False
    
    #map initialization
    char_map = {}
    for i in arr1:
        if i not in char_map:
            char_map[i] = 1
        else:
            char_map[i] += 1
    
    for i in arr2:
        if i not in char_map:
            return False
        elif char_map[i] == 0:
            return False
        else:
            char_map[i] -= 1
    
    return True

string1 = "abcdef"
string2 = "cbafedd"
res = checkPalin(string1,string2)
if(res):
    print("yes they are palindromes")
else:
    print("They are not palindromes")