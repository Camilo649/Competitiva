
import sys
sys.stdin = open('class.in', 'r') 
sys.stdout = open('class.out', 'w')

n, r, c = map(int, input().split())

grid = [
    [
        '.' for j in range(c)
    ]
    for i in range(r)
]


grid[0][0] = '#'
count = 1
x = 1

for i in range(1, n):
    x = (i + 1) // 2
    if x >= c or x >= r:
        break
    
    if i % 2 == 1:
        grid[0][x] = '#'
        count+= 1
    
    else:
        grid[x][0] = '#'
        count += 1



i = 0
while count < n:
    if grid[i//c][i%c] == '.':
        grid[i//c][i%c]  = '#'
        count += 1
    i += 1

print(min((n+1)//2, min(c, r)))
for i in range(r):
    print("".join(grid[i]))