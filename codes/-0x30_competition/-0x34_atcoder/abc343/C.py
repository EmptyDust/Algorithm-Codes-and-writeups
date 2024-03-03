
n=int(int(input())**(1/3))
for x in range(n,0,-1):
    num = x**3
    s = f'{num}'
    re = s[::-1]
    if s == re:
        print(s)
        exit()
