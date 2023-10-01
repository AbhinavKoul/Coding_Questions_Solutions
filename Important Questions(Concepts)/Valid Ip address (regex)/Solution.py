import re;

def isValidIp(ip : str)->bool:
    ipv4Regex = "(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])"
    ipv6regex = "((([0-9a-fA-F]){1,4})\\:){7}([0-9a-fA-F]){1,4}"
    if re.match(ipv4Regex,ip) or re.match(ipv6regex,ip):
        return True
    
    return False

print(isValidIp("123.232.233.222"))