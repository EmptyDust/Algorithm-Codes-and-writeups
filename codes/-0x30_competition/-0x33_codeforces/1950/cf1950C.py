n = int(input())

for _ in range(n):
    s = input()
    n = int(s[0:2])
    m = int(s[3:5])
    f = True
    if n<=11:
        f = True
    else:
        f=False
    if n >= 13:
        n-=12
    if n == 0:
        n = 12
    str = "AM"if f else "PM"
    if n < 10:
        print(0,end='')
    print(n,end='')
    print(':',end='')
    if m<10:
        print(0,end='')
    print(m,end=' ')
    print(str)
