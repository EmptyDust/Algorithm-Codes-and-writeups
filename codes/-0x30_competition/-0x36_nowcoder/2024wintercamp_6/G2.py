
t=int(input())
for _ in range(t):
    n=int(input())
    s=int(input())
    k=int(input())
    a=[int(x) for x in input().split()]
    if a[0]==-1:
        continue
    # print(a)
    sum=0
    for num in a:
        sum+=num
    if sum != s:
        print(f"WRONG in {_+1}:sum!=s")

    cnt=0
    for i in range(n-2):
        if a[i]==a[i+2] and a[i]>a[i+1]:
            cnt+=1

    if cnt!=k:
        print(f"WRONG in {_+1}:cnt!=k")
