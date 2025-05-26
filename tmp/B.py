a=["1","i","l","I"]
t=int(input())
for _ in range(t):
    s=input()
    for i  in s:
        if i not in a:
            print(i,end="")
    print()