from collections import Counter
n = int(input())
nums = list(map(int,input().split()))
dict = Counter(nums)

nums.sort(reverse=True)
tmp = []
def check(x):
    if dict[x] > 0:
        dict[x] -= 1
        return True
    if x % 2 == 0 or x <= 1:
        return False
    if dict[x // 2] > 0:
        dict[x // 2] -= 1
        tmp.append(x // 2)
        return check(x - x // 2)
    return False

ans = []

for x in nums:
    if dict[x] == 0:
        continue
    dict[x] -= 1
    if x % 2 == 1:
        if dict[x - 1] > 0:
            dict[x - 1] -= 1
            ans.append(x * 2 - 1)
        else:
            ans.append(x)
        continue
    if check(x + 1):
        ans.append(x * 2 + 1)
        tmp.clear()
        continue
    else:
        for p in tmp:
            dict[p] += 1
        tmp.clear()
    if check(x - 1):
        ans.append(x * 2 - 1)
        tmp.clear()
        continue
    else:
        for p in tmp:
            dict[p] += 1
        tmp.clear()
    ans.append(x)

print(len(ans))
for x in ans:
    print(x,end=' ')
