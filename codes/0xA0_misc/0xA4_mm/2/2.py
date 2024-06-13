T = int(input())

for _ in range(T):
    n = int(input())
    s = input()
    s = " " + s
    sp = [0]*(n+1)

    cl = [0]*(n+1)
    cr = [0]*(n+1)
    sl = [0]
    sr = [0]
    res = [0]*(n+1)

    for i in range(1,n+1):
        if s[i] == '<':
            cl[i] = 1
            sl.append(sl[-1]+i)
            sp[i] = 1
        else:
            cr[i] = 1
            sr.append(sr[-1]+i)
            sp[i] = -1
        cl[i] += cl[i-1]
        cr[i] += cr[i-1]
    
    for i in range(1,len(sl)):
        res[i] = sp[i] * i + (sl[i] - sl[cl[i]] - sr[cr[i-1]]) * 2
    for i in range(len(sl),n+1):
        res[i] = sp[i] * i + (n + 1) + (sl[-1] - sl[cl[i]] + sr[max(i-1-len(sl)+1,0)] - sr[cr[i-1]]) * 2
    print(' '.join(map(str,res[1:])))