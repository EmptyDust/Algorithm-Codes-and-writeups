t = int(input())
for _ in range(t):
    a, b, n = input().split()
    a, b, n = int(a), int(b), int(n)
    x, y = a % n, b % n
    ans = x * x + y * y
    v = set()
    v.add((0, 0))
    while (x, y) not in v:
        v.add((x, y))
        dis = x * x + y * y
        ans = min(ans, dis)
        times = min((n - x + a - 1) // a, (n - y + b - 1) // b)
        x = (x + times * a) % n
        y = (y + times * b) % n
    print(ans)