
n = int(input())

adyacencia = []

for i in range(n):
	L,R = map(int, input().split())
	adyacencia.append([L,i+1,R])

#debo reconstruir las listas.

visitados = [False]*(n+2)

listas = []

def re_lista(elemento):
	global visitados
	ind = len(listas)-1
	
	visitados[elemento[1]] = True
	
	if visitados[elemento[2]] == False and elemento[2] != 0:
		listas[ind].append(adyacencia[elemento[2]-1])
		re_lista(adyacencia[elemento[2]-1])
	if visitados[elemento[0]] == False and elemento[0] != 0:
		listas[ind].insert(0,adyacencia[elemento[0]-1])
		re_lista(adyacencia[elemento[0]-1])

for i in adyacencia:
	if not visitados[i[1]]:
		listas.append([])
		listas[len(listas)-1].append(i)
		re_lista(i)

lista_fin = []

#ahora uno las listas
for i in listas:
	lista_fin += i
#popngo los volares correctos
for i in range(0,len(lista_fin)):
	if i < len(lista_fin)-1:
		lista_fin[i][2] = lista_fin[i+1][1]
		
	if i > 0:
		lista_fin[i][0] = lista_fin[i-1][1]

lista_fin = sorted(lista_fin,key=lambda x:x[1])

for y in lista_fin:
	print(y[0], y[2])
