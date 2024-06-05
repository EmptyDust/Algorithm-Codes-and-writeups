mod = 998244353
n = int(input())
res = 1
isp = [0] * (n+1)
for i in range(2,n+1):
    if isp[i] == 0:
        for j in range(i*i,n+1,i):
            isp[j] = 0
        x = 1
        while x<= n/i:
            x*=i
        res = res * x %mod

ans = 0
sum = 0
cnt = 0

for i in range(1,n+1):
    cur = res * pow(i,-1,mod) 
    ans = ((ans + sum - cnt * cur % mod)%mod+mod)%mod
    sum = (sum+cur)%mod
    cnt += 1

print(ans)