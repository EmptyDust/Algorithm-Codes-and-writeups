inf = int(1e9)
ansx=inf
ansi=inf
def solve(l,cnt):
    global ansx,ansi
    if cnt > ansx:
        return
    if l<10:
        if ansx == cnt:
            ansi = min(ansi,l)
        if ansx > cnt:
            ansx = cnt
            ansi = l
        return
    r = 0
    pos = 1
    while l >= 10:
        r += (l%10)*pos
        l //= 10
        pos *= 10
        solve(r+l,cnt+1)

num = int(input())
solve(num,0)
print(ansx,end=' ')
print(ansi)