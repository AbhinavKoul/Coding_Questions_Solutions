def checkOneOdd_inMap(map:dict)->bool:
    '''
    Input: dictionary
    Output: Returns true if there is only one value as odd
    '''
    check_odd = False
    for value in map.values():
        if value%2 == 1:
            #if once already some character is odd times present
            if(check_odd):
                return False
            check_odd = True
    
    return True

def checkPalindromePossible(string:str)->bool:
    '''
    Time : O(N)
    Space: O(N) where N is the characters in the string
    '''
    char_map = {}
    #updating character map to the count of no of characters
    for i in string:
        if i not in char_map:
            char_map[i] = 1
        else:
            char_map[i]+=1
    #check if the map contains only one odd or not
    res = checkOneOdd_inMap(char_map)
    if(res):
        return True
    else:
        return False

####################################################################################################################################################

def toggleBit(bit_vector:int,position:int)->int:
    if(position<0):
        return bit_vector
    
    mask = 1<<position
    if (bit_vector & mask) == 0:
        bit_vector|=mask
    else:
        bit_vector&= ~mask
    
    return bit_vector

def checkOneOdd_inBITVECTOR(bit_vector:int)->int:
    return ((bit_vector & (bit_vector-1)) == 0)
def checkPalindromePossible_BITVECTOR(string:str)->bool:
    '''
    TIME : O(N)
    SPACE: O(1) - due to bit vector
    '''
    #bit vector initialization
    counter = 0
    for i in string:
        #find the bit value where we need to toggle the bit
        val = ord(i) - ord('a')
        counter = toggleBit(counter,val)
    
    return (counter == 0) or (checkOneOdd_inBITVECTOR(counter))
####################################################################################################################################################
        

print(checkPalindromePossible("tactcoa"))
print(checkPalindromePossible_BITVECTOR("hello"))
print(checkPalindromePossible_BITVECTOR("tactcoa"))