n,m=map(int,input().split())
g=list(map(int,input().split()))
x=0
t=0
h=[]
h.append([0,[0,0]])
for i in g:
    a=min(h[-1][0]+i+1,h[-1][1][0]+i+(h[-1][1][1]+1)**4)
    x=h[-1][1][1]