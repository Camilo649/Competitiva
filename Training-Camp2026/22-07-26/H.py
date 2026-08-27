
T = int(input())

T_arr = []

for t in range(T):
    T_arr.append([])
    n = int(input())

    for i in range(n):
        l, r = input().split()
        l = int(l)
        r = int(r)

        T_arr[t].append([l, r, i, -1])
    
    T_arr[t].sort(key=lambda x: x[0])

for t in range(T):
    arr = T_arr[t]

    b = arr[0][1]

    N = -1

    for i in range(1, len(arr)):
        if arr[i][0] > b:
            N = i
            break
        else:
            b = max(b, arr[i][1])
    
    if N == -1:
        print(-1)
    else:
        for i in range(N):
            arr[i][3] = 1
        for i in range(N, len(arr)):
            arr[i][3] = 2
        
        arr.sort(key=lambda x: x[2])
        res = []
        for i in range(len(arr)):
            res.append(str(arr[i][3]))
        
        print(" ".join(res))




