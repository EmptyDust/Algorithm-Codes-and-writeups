T = int(input())
for _ in range(T):
    s = input()
    ans = len(s)
    f = False
    for i in range(1,len(s)):
        if s[i] != s[i-1]:
            ans += len(s) - i
            f=True
            break
    if f:
        print(ans)
    else:
        print(ans-1)
