import math
from collections import Counter
def add(a, b):
    x = a[0] * b[1] + a[1] * b[0]
    y = a[1] * b[1]
    gcd = math.gcd(x, y)
    x //= gcd
    y //= gcd
    return (x, y)

def mul(a, b):
    x = a[0] * b[0]
    y = a[1] * b[1]
    gcd = math.gcd(x, y)
    x //= gcd
    y //= gcd
    return (x, y)

def muli(a, i):
    x = a[0] * i
    y = a[1]
    gcd = math.gcd(x, y)
    x //= gcd
    y //= gcd
    return (x, y)

def query(p, q):
    gcd = math.gcd(p, q)
    p //= gcd
    q //= gcd
    print(f'? {p} {q}')
    return tuple(map(int, input().split()))


def solve():
    n = int(input())
    dic = Counter()
    for _ in range(n):
        x, __ = map(int, input().split())
        dic[x] += 1
    # print(dic)
    a = list(dic.items())
    print(a)
    pre = (0, 1)
    ans = (0, 1)
    for i in range(len(a) - 1):
        x, times = a[i]
        y, _ = a[i + 1]
        if times == 1:
            mid = query(y + x, 2)
            now = muli(mid, 2) - pre
            ans = add(ans, mul(add(now, pre), (y - x, 2)))

            pre = now
    print(f'! {ans}')
    return

T = int(input())

for _ in range(T):
    solve()