#recursive helper function
def recursiveFunction(digits,result,current,index,mapping):
    #base case/end case
    if(len(digits)==len(current)):
        result.append(current)
        return
    
    characters = mapping[digits[index]]
    
    for char in characters:
        recursiveFunction(digits,result,current+char,index+1,mapping)

#driver code to initialize base conditions
def letterCombinations(self, digits):
    #base edge case
    if(len(digits)==0):
        return ""
        
    mapping = {
        "0" : "0",
        "1" : "1",
        "2" : "abc",
        "3" : "def",
        "4" : "ghi",
        "5" : "jkl",
        "6" : "mno",
        "7" : "pqrs",
        "8" : "tuv",
        "9" : "wxyz"
    }
    
    result = []
    #recursive leap of faith!!!!!!!!!!!
    recursiveFunction(digits,result,"",0,mapping)
    
    return result
