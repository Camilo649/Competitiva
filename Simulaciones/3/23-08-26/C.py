e = 10**-10
N = int(input())
Xc, Yc, Zc = map(int, input().split())
Xs, Ys, Zs = map(int, input().split())


points = []
for i in range(N):
    x, y = map(int, input().split())
    points.append((x,y))

for i in range(N):

    p0 = points[i]
    p1 = points[(i+1)%N]

    p0x = p0[0]; p0y = p0[1]
    p1x = p1[0]; p1y = p1[1]

    v0x = p1x - p0x
    v0y = p1y - p0y
    v0z = 0

    v1x = Xc - p0x
    v1y = Yc - p0y
    v1z = Zc - 0

    n = (v0y*v1z-v0z*v1y, -(v0x*v1z-v0z*v1x), v0x*v1y-v0y*v1x)
    if -((Xs-p0x)*n[0] + (Ys-p0y)*n[1] + (Zs-0)*n[2]) < -e:
        print('S')
        exit()

print('N')