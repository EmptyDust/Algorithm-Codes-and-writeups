

def solve():
    n = int(input())
    a = list(map(int,input().split()))
    a.sort()
    i = 0
    while a[i]==0:
        i+=1
    x = a[i]
    y = a[i+1]
    cnt = i
    for _ in range(cnt):
        y = y*10
    for j in range(i+2,n):
        y = y*10+a[j]
    print(x*y)

t = int(input())
for _ in range(t):
    solve()