T = int(input())

for _ in range(T):
    n = int(input())
    s = input()
    t = input()
    s = ' ' + s + '2'
    t = ' ' + t

    res = 0;idx = n;F = 1
    for i in range(n,0,-1):
        if s[i+1] > t[i]:
            res = 1
            idx = i
            F = 1
        elif F and s[i+1] == t[i]:
            res += 1
        else:
            F = 0
    print(s[1:1+idx]+t[idx:])
    print(max(1,res))