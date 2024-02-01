def ii():
    return [int(x) for x in input().split()]

n,w = ii()
MAXN=1000*n+1
INF=1e10
dp = [INF]*MAXN
dp[0]=0

for _ in range(n):
    wt,vl=ii()
    for x in range(MAXN-1,vl-1,-1):
        dp[x]=min(dp[x],dp[x-vl]+wt)

res=0
for x in range(MAXN-1,-1,-1):
    if dp[x]<=w:
        res=x
        break

print(res)