import math
from functools import reduce

n = int(input())
numeros = list(map(int,input().split()))

numsred= reduce(math.gcd,numeros)

spuede = True

for i in range(len(numeros)):
    numeros[i] = numeros[i]//numsred
    
    while numeros[i] % 2 == 0 or numeros[i] % 3 == 0:
        if numeros[i] % 2 == 0:
            numeros[i] = numeros[i]//2
        elif numeros[i] % 3 == 0:
            numeros[i] = numeros[i]//3 
    if numeros[i] != 1:
        spuede = False
        break

if spuede:
    print("Yes")
else:
    print("No")






