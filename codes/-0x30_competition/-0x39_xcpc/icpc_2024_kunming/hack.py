print(1)
print(10**5)
a, b = 1, 10 ** 5
array = []
for i in range(10**5//2):
    array.append(a)
    array.append(b)
    a += 1
    b -= 1

print(' '.join(map(str, array)))

# print(len(array)