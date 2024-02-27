from random import randint
from collections import defaultdict

n = int(input())
m = randint(10 ** 30, 10 ** 31)
nums = [int(input()) % m for _ in range(n)]

d = defaultdict(int)
for x in nums:
    d[x] += 1

ans = 0
for x in nums:
    for y in nums:
        ans += d[x * y % m]
print(ans)
