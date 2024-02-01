def ii():
    return [int(x) for x in input().split()]

n,w = ii()
dp=[0]*(w+1)

for i in range(n):
    wt,vl=ii()
    for j in range(w,wt-1,-1):
        dp[j]=max(dp[j],dp[j-wt]+vl)

print(dp[w])