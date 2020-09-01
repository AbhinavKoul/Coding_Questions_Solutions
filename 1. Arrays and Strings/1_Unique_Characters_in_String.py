def isUnique(arr:str)->bool:
    ''' USING EXTRA DATA STRUCTURE

    Space Complexity  : min(O(c),O(n)) where c is the character set (but we are taking 128 space for characters O(c) )
    Time Complexity   : O(n) WHERE n is length of string
    '''
    length = len(arr)
    # if greater than character limit, then dublicacy is obviosly there
    if(length>128):
        return False
    # map initialization
    char_set = {}
    for i in arr:
        #check key in map
        if(i in char_set):
            return False
        char_set[i] = 1
    
    return True

def isUnique_BitVector(arr:str)->bool:
    '''
    USING BIT VECTOR : OPTIMIZATION ON SPACE ASPECT!

    time complexity :   O(N)
    SPACE complexity:   O(1)

    Assume if character set is just from 'a' - 'z'.
    If more set, then we have to take diffirent data type rather than int    
    '''
    checker = 0  # bit vector of int as it has a size of 32 and since we hae 26 characters we can use bit manipulation to set flags

    for i in arr:
        val = ord(i) - ord('a') # find shift from initial char 'a' to set that flag at that position
        if((checker & (1<<val)) > 0): # shift left to location of character and compare with 0 bit and check if > 0  means checker also has 1 at that bit and thus already present
            return False
        #update checker flag
        checker |= (1<<val) # we do or here as we want to set/mask bit at that position(val) to 1 :- denoting that that char is present 
    
    return True
        

string = "abcdefghijklmnopqrst"
t = isUnique(string)
if(t):
   print("String " + string +" is Unique")
else:
   print("loooop")

m = isUnique_BitVector(string)
if(m):
   print("String " + string +" is Unique")
else:
   print("loooop")

