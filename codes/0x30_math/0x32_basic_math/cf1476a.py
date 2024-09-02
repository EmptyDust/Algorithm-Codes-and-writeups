import math
t = int(input())
for _ in range(t):
    n,k = map(int,input().split())
    if n > k:
        k = math.ceil(n / k) * k
    print(math.ceil(k / n))