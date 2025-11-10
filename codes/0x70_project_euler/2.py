x = 1
y = 2
sum = 0
while y <= 4000000:
    if y % 2 == 0: sum += y
    x, y = y, x + y

print(sum)