class Solution:
    def isUnique(self,arr):
        mapping = {}
        
        for i in arr:
            if i == '.':
                continue
            if i not in mapping:
                mapping[i] = 1
            else:
                mapping[i] += 1
                return False
       
        return True;
      
      
                
    def isValidSudoku(self, A: List[List[str]]) -> bool:
          #all rows

        for i in range(0,9):
            print(A[i][0:])                         #most imppp
            if not self.isUnique(list(A[i][0:])):
                return False
                print("false")
            else:
                print("true")
        
        for i in range(0,9):
            t = [row[i] for row in A]               #mosts impppp
            print(t)
            if not self.isUnique(t):
                return False
                print("false")
            else:
                print("true")
        for i in range(0,9,3): #0 1 2 ==> 0 3 6
            for j in range(0,9,3): # 0 1 2 ==> 0 3 6
                
                mat = [x[j:j+3] for x in A[i:i+3]]  #most imp
                t = [o for p in mat for o in p]
                print(t)
                if not self.isUnique(t):
                    return False
                    print("false")
                else:
                    print("true")
                    
        
        return True
        