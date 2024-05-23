t=int(input())
for _ in range(t):
    n=int(input())
    g=list(map(int,input().split()))
    re=[0]*20
    for i in range(20):
        t=-1
        for j in range(n):
            if g[j]&1:
                re[i]=max(re[i],j-t)
                t=j
            g[j]>>=1
        if re[i]!=0 and t!=-1:
            re[i]=max(re[i],n-t)
    print(max(max(re),1))
