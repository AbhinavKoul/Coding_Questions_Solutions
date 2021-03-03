def findDigitsInBinary(n):
    '''
    returns Binary notation in string format
    '''
    bin = []
    if n == 0:
        return "0"
    while(n>0):
        rem = n%2
        bin.append(str(rem))
        n = int(n/2)
    
    bin.reverse()
    
    wtr = "".join(bin)
    return wtr