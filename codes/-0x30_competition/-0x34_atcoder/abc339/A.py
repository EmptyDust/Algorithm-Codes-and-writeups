str = input()

ans=-1
for i in range(len(str)):
    if str[i] == '.':
        ans=i

print(str[ans+1:])