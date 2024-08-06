n,m = map(int,input().split())
N = 5001
dp = [0]*N
dp[0] = 1
for i in range(n):
    ndp = [0]*N
    a = list(map(int,input().split()))
    for x in a:
        for k in range(N-1,x-1,-1):
            ndp[k] |= dp[k - x]
    dp = ndp

t = int(input())
ans = int(1e9)
for i in range(N):
    if dp[i]:
        ans = min(ans,abs(i-t))
print(ans)