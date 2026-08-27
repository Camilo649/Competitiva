from math import sqrt

n, h = list(map(int, input().split()))

A = h / 2
a = A / n


r = []
for i in range(1, n):
    r.append(sqrt(2 * h * a * i))

for x in r[:-1]:
    print(x, end = " ")

print(r[-1])