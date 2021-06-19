def get_power_set(s):
  power_set=[[]]
  for elem in s:
    for sub_set in power_set:
      power_set=power_set+[list(sub_set)+[elem]]
  return power_set


l1 = [4,5,6,15]

b=get_power_set(l1)
b.remove([])
#print(b)

product=[]
for i in b:
 if len(i)==1:
  i=i[0]
  product.append(i)
 else:
  a=1
  for j in i:
   a*=j
  product.append(a)
  a=1
#print(product)
#4, 8, 2, 24, 6, 3, 360, 90, 45, 15

count=[]
def multiple(x):
   arr=[]
   a=x
   for i in range(2,x+1):
    for j in range(a):
     if a%i==0:
      arr.append(i)
      a=a//i
   s=set(arr)
   co=0
   if len(s)==len(arr):
    for i in arr:
      for j in range(2,i):
       if i%2==0:
        co=1
        break
    if co==0:
     #print(arr)
     count.append(1)
   
   
for i in product:
   multiple(i)
print(len(count))