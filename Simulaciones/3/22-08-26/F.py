from math import inf

N = int(input())
W, L, Tx, Ty = map(int, input().split())

closest = [inf, inf]

shotsAll = []

for team in [0, 1]:
    shots = []
    for i in range(N):
        x, y = map(int, input().split())
        d = (x-Tx)**2 + (y-Ty)**2
        shots.append(d)
        if d < closest[team]:
            closest[team] = d

    shotsAll.append(shots)

w = 0 if closest[0] < closest[1] else 1
l = 1 if closest[0] < closest[1] else 0

shots = shotsAll[w]
target = closest[l]

ans = 0

for d in shots:
    if d < target:
        ans += 1

print(['A', 'R'][w], ans)

