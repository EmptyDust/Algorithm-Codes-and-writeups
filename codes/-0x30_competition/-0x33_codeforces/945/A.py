t=int(input())
for _ in range(t):
    p1,p2,p3=map(int,input().split())
    if (p1+p2+p3)%2==1:
        print(-1)
        continue
    if p3<=(p1+p2+p3)//2:
        print((p1+p2+p3)//2)
    else:
        print(p2+p1)