from math import sqrt

def allFactors(A):
    '''
    Time : O(Nlog(N)) ==> due to sorting at end
    '''
    factors = []
    # dor range sqrt + 1 for the edge case when N = 1
    for i in range(1,int(sqrt(A)+1)):
        if A%i == 0:
            factors.append(i)
            if(i!=sqrt(A)):
                factors.append(int(A/i))
    
    return sorted(factors)
# ---------------------------------------------------------------- more effective ------------------------------------------------------
def allFactors_without_sorting(A):
    '''
    Time : O(sqrt(N)) ==> eliminate sorting
    '''
    factors_below_sqrt_A = []
    factors_above_sqrt_A = []

    for i in range(1,(int(sqrt(A))+1)):
        if A%i == 0:
            factors_below_sqrt_A.append(i)
            if(i!=sqrt(A)):
                factors_above_sqrt_A.append(int(A/i))
    
    factors_above_sqrt_A.reverse()
    
    factors_below_sqrt_A.extend(factors_above_sqrt_A)
    return factors_below_sqrt_A

A = 36
ans = allFactors_without_sorting(A)
print(ans)


    
