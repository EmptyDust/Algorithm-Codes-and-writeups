from random import randint,shuffle

T = randint(1,100)
print(T)

for _ in range(T):
    n = randint(1,10000)
    m = randint(0,n)

    cnt0 = randint(0,n)
    sy = n - cnt0

    a = ['0']*cnt0

    for i in range(sy):
        x = randint(0,int(1e9))
        a.append(f'{x}')
    
    shuffle(a)

    print(f'{n} {m}')
    print(' '.join(a))