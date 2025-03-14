from random import randint,shuffle
import random
import math

T = 1

for _ in range(T):
    n = randint(1,10)
    print(f"{n} 1")
    
    sum = 0
    for _ in range(n):
        x = randint(1,4)
        print(x,end=' ')
        sum += x
    print()
    l = randint(1,sum)
    r = randint(l,min(l+7,sum))
    print(f"{l} {r}")