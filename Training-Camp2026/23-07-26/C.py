

grilla = []

n m k = map(int,input().split())

for i in range(n):
    grilla.append(list(input()))


nodos = {

}

for x in grilla:
    for y in x:
        if not (x,y) in nodos:
            if x > 0 and grilla[x+1][y] == '#':
                pass
            if x < 0 and grilla[x+1][y] == '#':
                pass
            if y > 0 and grilla[x+1][y] == '#':
                pass
            if x < 0 and grilla[x+1][y] == '#':
                pass

