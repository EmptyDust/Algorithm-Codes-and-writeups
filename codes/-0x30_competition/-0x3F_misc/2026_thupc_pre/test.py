


k, S1, S2 = map(int, input().split())
left = (S1 + S2) ** 2 / (k + 1) ** 2
right = S1 ** 2 / k ** 2 + S2 ** 2 / (k + 2) ** 2
print(left)
print(right)
print(left < right)