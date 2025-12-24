from random import randint
n = int(50)
q = 1
print(f'{n} {q}')
for _ in range(n):
    print(randint(1, 10), end=' ')
print()
l = randint(1, n)
r = randint(l, n)
print(f"{l} {r}")