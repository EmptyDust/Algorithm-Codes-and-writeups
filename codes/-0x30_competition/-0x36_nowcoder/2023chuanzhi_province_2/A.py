def ii():
    return [int(x) for x in input().split()]

n,a=ii()
nums=ii()

pre=101
cnt=0

for num in nums:
    if num>=a and pre<a:
        cnt+=1
    pre=num

print(cnt)