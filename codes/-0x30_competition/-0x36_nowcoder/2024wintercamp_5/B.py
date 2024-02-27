import re

mod = int(1e9 + 7)
str = input()
length = len(str) + 1

p = [r'mygo',
     r'm.ygo',
     r'my.go',
     r'myg.o',
     r'm.y.go',
     r'm.yg.o',
     r'my.g.o',
     r'm.y.g.o']
f = [1] * length
for i in range(2, length):
    f[i] = (f[i - 1] + f[i - 2]) % mod

ans = 0
for t in p:
    i = 0
    pattern = re.compile(t)
    while i < length:
        match = pattern.search(str, i)
        if not match:
            break
        s = match.start()
        e = match.end()
        ans += f[length - e] * f[s + 1] % mod
        # print(length-e)
        # print(s)
        ans %= mod
        i = s + 1

print(ans)
