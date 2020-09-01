def isUnique(arr:str)->bool:
    ''' USING EXTRA DATA STRUCTURE

    Space Complexity  : min(O(c),O(n)) where c is the character set (but we are taking 128 space for characters O(c) )
    Time Complexity   : O(n) WHERE n is length of string
    '''
    length = len(arr)
    if(length>128):
        return False
    char_set = {}
    for i in arr:
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
    checker = 0

    for i in arr:
        val =ord(i) - ord('a')
        if((checker & (1<<val)) > 0):
            return False
        
        checker |= (1<<val)
    
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

