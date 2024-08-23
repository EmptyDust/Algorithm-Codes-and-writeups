import math

n, k = map(int,input().split())
f = list(map(int,input().split()))

Fa = [0.0] * n
Fb = [0.0] * n
for t in range(n):
    for s in range(n):
        if s != k:
            Fa[t] += f[s] * math.cos(2 * math.pi * s * t / n)
            Fb[t] -= f[s] * math.sin(2 * math.pi * s * t / n)

B = 20000
ans = 1e18
fk = 0
for x in range(-B,B,1):
    res = 0
    for t in range(n):
        a = Fa[t] + x * math.cos(2 * math.pi * k * t / n)
        b = Fb[t] - x * math.sin(2 * math.pi * k * t / n)
        res = max(res, math.sqrt(a * a + b * b))
    if(ans > res):
        fk = x
    ans = min(ans, res)
print(ans,fk)

# print(f'a:{max(Fa)},b:{max(Fb)}')
# print(Fa)
# print(Fb)
