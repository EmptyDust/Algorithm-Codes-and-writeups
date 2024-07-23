t = int(input())
for _ in range(t):
    s = input()
    t = s.split("://")
    print(t[0])
    a = t[1].split("/")
    print(a[0])
    for b in a[1:]:
        if b != "":
            print(b)