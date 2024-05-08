import math
def MII():
    return map(int,input().split())

def exgcd(a,b):
    if b==0:
        return a,1,0
    d,y,x = exgcd(b,a%b)
    y -= a // b * x
    return d,x,y

def solve():
    N,M = MII()
    m1,a1 = 1,0
    for _ in range(N):
        m2,a2 = MII()
        
        if m1 == 1:
            m1,a1 = m2,a2
            continue

        a = a2 - a1
        g = math.gcd(m1,m2)

        if a%g != 0:
            print("he was definitely lying")
            return
        
        d,x,y = exgcd(m1,m2)
        l = m1 // g * m2
        x0 = x * a // g
        b = ((m1 * x0 + a1) % l + l) % l
        m1,a1 = l,b

    if a1 <= M:
        print(a1)
    else:
        print("he was probably lying")

solve()
    
        