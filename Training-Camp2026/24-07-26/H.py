

n = int(input())

arr = []



for i in range(n):
    arr.append(i+1)
def solve():
    if n < 4:
        print("NO")
        return
    
    print("YES")
    if n == 4:
        print(1, "*", 2, "=", 2)
        print(2, "*", 3, "=", 6)
        print(6, "*", 4, "=", 24)
        return

    while len(arr) > 5:
        ultimo = arr[len(arr)-1]
        ault = arr[len(arr)-2]

        if ultimo == 1:
            print(ultimo, "*",ault, "=", ault)
            arr.pop()
        else:
            num = ultimo -ault
            print(ultimo, "-", ault, "=", num)
            arr.pop()
            arr.pop()
            arr.append(num)
    if arr[len(arr)-1] == 1:
        arr.pop()
        print(1, "*", 4, "=", 4)
        print(1, "*", 2, "=", 2)
        print(2, "*", 3, "=", 6)
        print(6, "*", 4, "=", 24)
    else:
        arr.pop()
        print(5, "+", 1, "=", 6)
        print(6, "*", 4, "=", 24)
        print(3, "-", 2, "=", 1)
        print(1, "*", 24, "=", 24)

solve()