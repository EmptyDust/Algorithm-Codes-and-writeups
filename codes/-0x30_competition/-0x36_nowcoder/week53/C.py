n = int(input())
s = input()
x,y,z = map(int,input().split())
cnt = 0
ans = 0
for ch in s:
    if ch == '1':
        if cnt:
            cnt -= 1
            ans += 1
    else:
        cnt += 1
print(ans)