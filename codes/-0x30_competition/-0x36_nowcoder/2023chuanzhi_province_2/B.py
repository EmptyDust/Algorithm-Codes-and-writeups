s=input()

res=0

for i in range(2,len(s)):
    cnt=1
    for j in range(2,len(s)):
        if i!=j and s[j]==s[j-2] or j-2==i and s[j]==s[j-4]:
            cnt+=1
    res=max(cnt,res)

print(res)