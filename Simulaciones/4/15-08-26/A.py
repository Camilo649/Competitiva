import sys
sys.stdin = open('alex.in','r')
sys.stdout = open('alex.out','w')

a, b = map(int, (input().split()))

if a > b:
    c = a
    a = b
    b = c

x1 = min(a, b/3)
x2 = a/2

print(max(x1, x2))