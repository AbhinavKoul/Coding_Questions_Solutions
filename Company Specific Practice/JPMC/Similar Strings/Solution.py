def solution(a:str,b:str)->bool:
    if a == b:
        return True
    else:
        ptr  = len(a)//2
        a1 = sorted(list(a[0:ptr])) 
        a2 = sorted(list(a[ptr:]))

        ptr = len(b)//2
        
        b1 = sorted(list(b[0:ptr]))
        b2 = sorted(list(b[ptr:]))

        if (a1 == b1 and a2 == b2) or (a1 == b2 and a2 == b1):
            return True

    return False


if __name__ == "__main__":
    a = "abab"
    b = "abba"
    if(solution(a,b)):
        print("YES")
    else:
        print("NO")

