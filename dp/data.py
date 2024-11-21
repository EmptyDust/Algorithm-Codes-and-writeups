from random import randint,shuffle
import random

T = 1
print(T)

for _ in range(T):
    n = randint(1,10)
    print(n)
    
    for _ in range(n):
        print('B' if randint(0,1) else 'R',end = '')