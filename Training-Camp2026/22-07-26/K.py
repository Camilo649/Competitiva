n = int(input())


numeros = list(map(int,list(input())))
cant8 = 0
cantoc = 0
for i in range(len(numeros)-10):
    num = int(numeros[i])
    if num == 8:
        cant8 += 1
    else:
        cantoc += 1
#print(cant8,cantoc)
if cantoc <= cant8:
    print("YES")
else:
    print("NO")

