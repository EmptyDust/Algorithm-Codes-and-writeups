from random import randint

t = 10
print(t)
sum=0
cnt=0
n = randint(1,10**5)
m = randint(1,10**5)
inf = int(1e9)
'''
for n in range(1,100):
    for m in range(n+1,1000):
        k = randint(1,min(n*m,10**5))
        print(f'{n} {m} {k}')
        for i in range(n):
            print(inf-i,end=' ')
        print()
        for i in range(m):
            print(inf-1000+i,end=' ')
        print()
        sum+=k
        cnt+=1
'''
for _ in range(t):
    k=min(m*n,10**5)
    if sum+k>10**6:
        break
    print(f'{n} {m} {k}')
    for _ in range(n):
        a = randint(1,999)
        print(a,end=' ')
    print()
    for _ in range(m):
        b = randint(1,999)
        print(b,end=' ')
    print()
    sum+=k
    cnt+=1

print(sum)
print(cnt)