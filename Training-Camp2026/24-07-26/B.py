n = int(input())

arr = list(map(int, input().split()))


k = 0
c1 = arr[0]
c2 = arr[1]

comb = (c1, c2)
if comb in {(2,3), (3,2)}:
    print("Infinite")
    exit()
if comb in ((1,2),(2,1)):
    k += 3
if comb in ((1,3),(3,1)):
    k += 4

for i in range(2, n):
    c0 = arr[i-2]
    c1 = arr[i-1]
    c2 = arr[i]

    if (c1,c2) in {(2,3), (3,2)}:
        print("Infinite")
        exit()

    elif (c0, c1, c2) == (3, 1, 2):
        k += 2

    elif (c1, c2) in ((1,2),(2,1)):
        k += 3
    elif (c1, c2) in ((1,3),(3,1)):
        k += 4

else:
    print("Finite")
    print(k)