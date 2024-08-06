a = input()
ans = 0
for i in range(len(a)//2):
    j = len(a) - i - 1
    ans += min(abs(ord(a[i]) - ord(a[j])),abs(ord('z') - ord(a[j]))+abs(ord(a[i]) - ord('a'))+1,abs(ord('z') - ord(a[i]))+abs(ord(a[j]) - ord('a'))+1)
print(ans)