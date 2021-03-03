def romanToInteger(roman:str)->int:
    converter = {
                    {'I',1},
                    {'V',5},
                    {'X',10},
                    {'L',50},
                    {'C',100},
                    {'D',500},
                    {'M',1000}
    }
    result = 0
    n = len(roman) - 1

    for i in range(n,-1,-1):
        character = roman[i]

        if(i==n):
            result += converter[character]
        else:
            if(converter[character]<converter[roman[i+1]]):
                result -= converter[character]
            else:
                result += converter[character]
    
    return result