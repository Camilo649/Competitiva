sides = list(map(int, input().split()))

ans = 0

for (l1, l2, l3) in (sides[:3], sides[3:]):
    r = min(l1, l3)
    ans += r * (l2*2 +1) + ((r - 1)*r)

l1, l2, l3 = sides[:3]

h = abs(l1-l3)
R = l2 + min(l1, l3)

ans += h*2*R

print(ans)