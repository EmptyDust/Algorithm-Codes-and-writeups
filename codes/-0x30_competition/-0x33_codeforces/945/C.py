t=int(input())
for _ in range(t):
    n=int(input())
    g=list(map(int,input().split()))
    
    for i in range(n):
        if g[i]==1:
            a=i
        if g[i]==n:
            b=i
    k=1
    if abs(a-b)==1:
        k=2-(i+1)%2
    for i in range(n):
        g[i]=[g[i],i]
    ans=[0]*n
    a=[]
    b=[]
    for i in range(k,n-1,2):
        a.append(g[i])
    for j in range(k-1,i+2,2):
        b.append(g[j])
    a.sort()
    b.sort(reverse=True)
    tmp=n
    for v,w in a:
        ans[w]=tmp
        tmp-=1
    tmp=1
    for v,w in b:
        ans[w]=tmp
        tmp+=1
    if k==1:
        ans[-1]=tmp
    else:
        ans[0]=tmp
    for i in ans:
        print(i,end=" ")
    print()
