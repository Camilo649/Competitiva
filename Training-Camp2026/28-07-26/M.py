tests = int(input())

for _ in range(tests):
    n, k = list(map(int, input().split()))

    if k % (n-1) == 0:
        m = k // (n-1)
        print(m*n - 1)
    else:
        m = k // (n-1)
        print((k%(n-1)) + n * m)


        