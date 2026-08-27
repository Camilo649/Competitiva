


cad = input()

numeros = []

i = 0
while i<len(cad):
    cn = ""
    j = 0

    while (i+j)<len(cad) and cad[j+i] in ["0","1","2","3","4","5","6","7","8","9",'.']:
        cn += cad[i+j]
        j += 1
    if cn != "":
        cn = cn[::-1]
        i = i+j
        numeros.append(cn)
    i +=1

ent = 0
dic = 0.0

for i in numeros:
    decimal = ""
    entero = ""
    
    cn = ""

    indiniti = 0
    if len(i) > 2 and i[2] == '.':
        decimal += i[0]+i[1]+"."+"0"
        indiniti += 3
    
    for y in range(indiniti,len(i)):
        if i[y] != ".":
            entero += i[y]
    if len(decimal) > 1:
        decimal = decimal[::-1]
        decimal = float(decimal)
        dic +=decimal

    entero = entero[::-1]
    entero = int(entero)
    ent += entero
ent += int(dic)
dic = dic-int(dic)
dic = round(dic,2)

ent = str(ent)[::-1]
dic = str(dic)[::-1]

rta = ""

for t in range(len(dic)):
    if dic == "0.0":
        break
    if dic[t] == '.':
        rta += '.'
        break
    if len(dic) < 4:
        rta += '0'
    rta += dic[t]
#print(rta)

for y in range(len(ent)):
    if (y) % 3 == 0 and y != 0:
        rta += '.'
    rta += ent[y]
rta = rta[::-1]

print(rta)


