a,b,n = map(int,input().split())

ans = n
for x in range(10000):
    ans = min(ans,a*a*pow(b*b,))