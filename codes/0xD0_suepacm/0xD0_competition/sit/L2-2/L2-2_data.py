from random import randint

t = 3
print(t)
sum=0
for __ in range(t):
    n = randint(1,3)
    m = randint(1,3)

    k = randint(1,min(n*m,10**6))
    print(f'{n} {m} {k}')

    for _ in range(n):
        a = randint(1,10)
        print(a,end=' ')
    print()
    for _ in range(m):
        b = randint(1,10)
        print(b,end=' ')
    print()
    sum+=k
# print(sum)