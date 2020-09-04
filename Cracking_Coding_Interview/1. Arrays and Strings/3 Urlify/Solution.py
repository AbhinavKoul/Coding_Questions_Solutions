def urlify(string:str)->str:
    '''
    copying to a diffirent/same string again - time taken to copy also added
    '''
    string = string.strip()
    return string.replace(" ","%20")
    

string1 = "Mr John Smith       "
print(urlify(string1))