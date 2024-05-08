n = int(input())
s = input()

a = ["FZ", "ZZ", "QZ", "PT","LY", "NP", "ND", "XM", "SM"]
b = ["fuzhou", "zhangzhou", "quanzhou","putian", "longyan", "nanping", "ningde","xiamen", "sanming"]

ans = []
mx = -1
for i in range(len(a)):
    if s.count(a[i]) > mx:
        ans.clear()
        mx = s.count(a[i])
    if s.count(a[i]) == mx:
        ans.append(b[i])


print(' '.join(sorted(ans)))