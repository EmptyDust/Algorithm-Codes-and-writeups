import random
test = 100000
print(test)

f = int(1e9)
k = 1
sum=0
cnt=0

for n in range(100):
    for s in range(n,n+100):
        for k in range(1,n//2):
            # print(f"{n} {s} {k}")
            sum+=n
            cnt+=1
print(cnt)
#100000
#