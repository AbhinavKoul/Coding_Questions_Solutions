'''
USING RECURSIVE APPROACH
'''
def resize_2D_matrix(l,n):
    '''
    params : Array and column
    '''
    return [l[i:i+n] for i in range(0, len(l), n)]

def spiralprint(A,r1,r2,c1,c2):
    # if nothing left to print
    if ((c2-c1)< 0) or ((r2-r1)<0):
        return
    #if only one row or col left to print
    if r2 == r1:
        for i in range(c1,c2+1,1):
            print(A[r1][i],end=" ")
        return
    if c2 == c1:
        for i in range(r1,r2+1,1):
            print(A[i][c1],end=" ")
        return
    
    #normal case
    
    for i in range(c1,c2,1):
        print(A[r1][i],end=" ")
    for i in range(r1,r2,1):
        print(A[i][c2],end=" ")
    for i in range(c2,c1,-1):
        print(A[r2][i],end=" ")
    for i in range(r2,r1,-1):
        print(A[i][c1],end=" ")
    
    #recursion to go to inner similar structure
    spiralprint(A,r1+1,r2-1,c1+1,c2-1)
    
if __name__ == "__main__":
    for _ in range(int(input())):
        R,C = map(int,input().split())
        raw = [*map(int,input().split())]
        A = resize_2D_matrix(raw,C)
        r1,r2,c1,c2 = 0,R-1,0,C-1
        #print(A)
        spiralprint(A,r1,r2,c1,c2)
        print()
