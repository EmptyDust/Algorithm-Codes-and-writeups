t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]
    ans = 0
    for num in a:
        ans+=abs(num)
    print(ans)