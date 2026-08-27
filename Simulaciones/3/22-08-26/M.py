

e = 10**-10

n, T = map(int, input().split())

TP = T * 0.75
TN = T * 0.25

P = []
N = []

for i in range(n):
    prio, mb = input().split()
    mb = int(mb)
    if prio == 'P':
        P.append(mb)
    else:
        N.append(mb)

P.sort()
P.reverse()
N.sort()
N.reverse()

ans = 0

while P or N:
    lenP = len(P)
    lenN = len(N)
    if P and N:
        t = min(P[-1]/(TP/lenP), N[-1]/(TN/lenN))

        ans += t
        for i in range(lenP-1, -1, -1):
            P[i] -= t*TP/lenP
            if abs(P[i]) < e:
                P.pop()
        for i in range(lenN-1, -1, -1):
            N[i] -= t*TN/lenN
            if abs(N[i]) < e:
                N.pop()
    
    elif P:
        t = P[-1] / (T/lenP)
        ans += t
        for i in range(lenP-1, -1, -1):
            P[i] -= t * T/lenP
            if abs(P[i]) < e:
                P.pop()
    else:
        t = N[-1] / (T/lenN)
        ans += t
        for i in range(lenN-1, -1, -1):
            N[i] -= t * T/lenN
            if abs(N[i]) < e:
                N.pop()


print(ans)