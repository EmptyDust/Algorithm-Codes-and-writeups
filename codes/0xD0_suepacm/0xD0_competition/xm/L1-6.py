x,y = map(int,input().split())
a = [float(x)*12/100 for x in input().split()]
b = list(map(int,input().split()))

dp = [float(x)]*(y+1)

for i in range(y):
    for j in range(4):
        if i + b[j] <= y:
            dp[i+b[j]] = max(dp[i+b[j]],dp[i]*(1+b[j]*a[j]))

print(round(dp[y],2))