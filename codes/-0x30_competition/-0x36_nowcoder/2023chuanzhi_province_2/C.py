from collections import Counter

n, k = [int(x) for x in input().split()]
s = input()

cnt = [x[1] for x in Counter(s).items()]

ans = 0
for num in sorted(cnt, reverse=True):
    if k>0:
        ans+=min(k,num)**2
        k-=num
    else:
        break

print(ans)
