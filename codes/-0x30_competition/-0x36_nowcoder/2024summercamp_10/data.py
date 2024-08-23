import random

n = random.randint(1,20 + 1)
k = random.randint(0,n)
print(f'{n} {k}')
for i in range(n):
    print(random.randint(-2000,2000),end = ' ')