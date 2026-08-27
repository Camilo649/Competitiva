def f(a,b):
    return a*a + b*b - a*b - b*a


N = int(input())
arr = list(map(int, input().split()))

m = min(arr)
M = max(arr)
print(f(m, M))