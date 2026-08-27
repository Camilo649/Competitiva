
from collections import defaultdict

s = input()
t = input()

ms = defaultdict(int)
mt = defaultdict(int)

for i in s:
    ms[i] += 1
for j in t:
    mt[j] += 1

sepuede = True

for y in mt:
    if mt[y] > ms[y]:
        sepuede = False

if sepuede:
    ordenado = True
    ind = 0
    for ti in t:
        if len(s) == ind:
            ordenado = False
            break
        while ti != s[ind]:
            if ind == len(s)-1:
                ordenado = False
                break
            ind +=1
        ind +=1
        if ordenado == False:
            break
    
    if len(s) == len(t):
        print("array")
    else:
        if ordenado:
            print("automaton")
        else:
            print("both")
else:
    print("need tree")