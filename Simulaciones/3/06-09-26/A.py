n = int(input())
sc = 0
sv = 0
I = []
for i in range(n):
    x, y = map(int, input().split())
    sc += x
    sv += y
    I.append((sc - sv)/(sc + sv))


m = int(input())

for i in range(m):
    q = int(input())

    if I[q-1] > 0:
        print("COMPRA")
    if I[q-1] == 0:
        print("NEUTRO") 
    if I[q-1] < 0:
        print("VENDA") 