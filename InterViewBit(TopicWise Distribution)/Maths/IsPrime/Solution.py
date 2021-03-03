from math import sqrt

def isPrime(self, n:int)->bool:
    '''
    TIME : O(root(N))
    '''
    if n == 0 or n == 1:
        return False
    
    for i in range(2,int(sqrt(n))+1):
        if n % i == 0:
            return False
    
    return True