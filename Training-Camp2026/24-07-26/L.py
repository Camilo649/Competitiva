



n = int(input())
personas = []

mp = {

}

for i in range(n):
    o,p = input().split()
    p = int(p)
    personas.append((o,p))

pinit = 0

for y in personas:
    if not y[1] in mp:
        if y[0] == '-':
            pinit += 1
            mp[y[1]] = 1
        else:
            mp[y[1]] = 1
rta = pinit
for i in personas:
    if i[0] == '+':
        pinit += 1
    else:
        pinit -= 1
    rta = max(rta,pinit)

print(rta)



