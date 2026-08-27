from math import gcd

def sign(x):
    if x >= 0:
        return 1
    return -1

n = int(input())

divisors = {}

extra = 0

a_arr = list(map(int,input().split()))
b_arr = list(map(int,input().split()))

for i in range(n):
    a = a_arr[i]
    b = b_arr[i]

    if a == 0:
        if b == 0:
            extra += 1
        continue
    
    m = gcd(a, b)
    c = (sign(a) * sign(b) * abs(b)//m, abs(a)//m)

    if c not in divisors:
        divisors[c] = 0
    
    divisors[c] += 1

max_value = 0
for value in divisors.values():
    if value > max_value:
        max_value = value

print(max_value + extra)


