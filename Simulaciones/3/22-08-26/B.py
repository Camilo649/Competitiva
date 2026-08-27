N = int(input())

ans = 0

for _ in range(N):
    row = input()
    b = 0
    for c in row:
        if c == 'N':
            b += 1
        else:
            b = 0
        if b == 2:
            ans += 1
            b = 0

print(ans)