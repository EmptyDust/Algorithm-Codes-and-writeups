n,m = map(int,input().split())
a = list(map(int,input().split()))
ans = sum(a)-max(a)
if ans > m:
    print(-1)
else:
    print(m-ans)