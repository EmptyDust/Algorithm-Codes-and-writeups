T = int(input())
for _ in range(T):
    x = int(input())
    res = x & -x
    if res ^ x == 0:
        if res == 1:
            res += 2
        else:
            res += 1
    print(res)
