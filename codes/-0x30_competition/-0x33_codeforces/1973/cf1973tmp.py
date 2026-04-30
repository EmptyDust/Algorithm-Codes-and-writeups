a = list(map(int,input().split()))
a.sort(reverse=True)

x = abs(int(input()))

for num in a:
    if x > num:
        x -= num
    else:
        x = num - x

print("Yes" if x == 0 else "No")