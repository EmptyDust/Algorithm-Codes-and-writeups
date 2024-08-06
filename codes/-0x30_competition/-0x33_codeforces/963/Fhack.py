n = 100
q = 100000
a = [1] * n
for i in range(2,44):
    a[i] = a[i-1] + a[i-2]

print(f"{n} {q}")
b = []
for x in a:
    b.append(str(x))
print(' '.join(b))
for _ in range(q):
    print("1 45")