T=int(input())
for _ in range(T):
    n=input()
    for i in ("0","2","4","5","6","8"):
        d=n.find(i)
        if d!=-1:
            break
    s=n[:d][::-1]+n[:d:-1]+i
    print(s)