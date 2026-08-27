


tests = int(input())


for test in range(tests):
    n, k = map(int,input().split())

    A = list(map(int,input().split()))
    B = list(map(int,input().split()))
    

    rta = 0
    preai = 0
    bestbi = 0
    for i in range(min(n,k)):

        preai += A[i]

        if B[i] > bestbi:
            bestbi = B[i]
        rta = max(rta,preai+bestbi*(k-i-1))
    


    print(rta)

