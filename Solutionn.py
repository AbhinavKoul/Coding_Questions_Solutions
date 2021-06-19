import math
from functools import reduce
import itertools
def primefactors(n):
  l=[]
  count=0
  while n % 2 == 0:
    l.append(2)
    n = n / 2
  for i in range(3,int(math.sqrt(n))+1,2):
    
    while (n % i == 0):
      l.append(i)
      n = n / i
    
  if n > 2:
    l.append(n)
  if len(l) == len(set(l)):
    count+=1 
  return(count)
 
def count(arr):
  a=0
  for i in range(len(arr)+1):
    for j in range(i):
      x=reduce((lambda x,y:x*y),arr[j:i])
      a+=primefactors(x)
  print(a)


t=int(input())
for i in range(t):
  n=int(input())
  arr = list(map(int,input().strip().split()))[:n]
  count(arr)