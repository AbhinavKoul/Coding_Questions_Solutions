'''
BASED ON BASE CONVERSION
'''

def titleToNumber(A):
    n = len(A)
    map = dict(zip("ABCDEFGHIJKLMNOPQRSTUVWXYZ",range(1,27)))
    
    sum = 0
    for i in range(0,n):
        sum += map[A[i]]*pow(26,n-i-1)
    
    return sum

print(titleToNumber("ABC"))
print(titleToNumber("A"))
print(titleToNumber("AB"))