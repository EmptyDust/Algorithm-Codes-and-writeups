n = int(input())
s = list(map(int,input().split()))
m = 0;ma = 0#5 3 4 2 4

suf = s.copy()
for i in range(n - 2, -1, -1):
    suf[i] = min(suf[i], suf[i + 1])

for i in range(n):
    m += 1
    if m // suf[i] > 0:
        ma += m // suf[i]
        m = m % suf[i]
print(ma)

