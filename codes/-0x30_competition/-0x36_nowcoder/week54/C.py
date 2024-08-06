from collections import Counter
n, m = map(int, input().split())
a = list(map(int, input().split()))
c = Counter(a)

ans = 0
k = c[1]

for i in range(1,m + 1):
    k = min(k, c[i])
    ans += k
    if k == 0:
        break

print(ans)