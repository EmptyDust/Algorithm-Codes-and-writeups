

def qpow(x,p):
    ret = 1
    while p:
        if p & 1:
            ret = ret * x
        p >>= 1
        x = x * x
    return ret

def ceil_sqrt(x):
    l = 0;r = int(1e30)
    while l < r:
        mid = l + r >> 1
        if mid * mid >= x:
            r = mid
        else:
            l = mid + 1
    return l

def floor_sqrt(x):
    l = 0;r = int(1e30)
    while l < r:
        mid = l + r >> 1
        if mid * mid > x:
            r = mid
        else:
            l = mid + 1
    return l - 1

def solve():
    n = int(input())
    n //= 2
    l,r = map(int,input().split())
    ll = l // qpow(10, n);lr = l % qpow(10, n)
    rl = r // qpow(10, n);rr = r % qpow(10, n)
    cnt = floor_sqrt(qpow(10, n) - 1) + 1
    lmin = ceil_sqrt(ll);lmax = floor_sqrt(rl)
    rmin = ceil_sqrt(lr) + 1;rmax = floor_sqrt(rr) + 1
    if lmin > lmax:
        print(0)
        return
    if lmin == lmax:
        sq = lmin * lmin
        if sq == ll and sq == rl:
            if rmin > rmax:
                print(0)
            else:
                print(rmax - rmin + 1)
        elif sq > ll and sq < rl:
            print(cnt)
        elif sq > ll:
            print(rmax)
        else:
            print(cnt - rmin + 1)
        return
    ans = (lmax - lmin - 1) * cnt
    if lmin * lmin > ll:
        ans += cnt
    else:
        ans += cnt - rmin + 1
    if lmax * lmax < rl:
        ans += cnt
    else:
        ans += rmax
    print(ans)

solve()
    