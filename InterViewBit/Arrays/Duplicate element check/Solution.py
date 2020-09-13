class Solution:
    # @param A : tuple of integers
    # @return an integer
    def repeatedNumber(self, A):
        char_Set = {}
        # make dictionarty
        for i in A:
            if(i in char_Set):
                char_Set[i] += 1
            else:
                char_Set[i] = 1
        
        for key,value in char_Set.items():
            if(value>1):
                return key