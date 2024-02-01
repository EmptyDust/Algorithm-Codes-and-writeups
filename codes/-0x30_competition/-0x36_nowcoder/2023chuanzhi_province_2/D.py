def is_prime(x):
    if (x == 2) or (x == 3):
        return True
    if (x % 6 != 1) and (x % 6 != 5):
        return False
    for i in range(5, int(x ** 0.5) + 1, 6):
        if (x % i == 0) or (x % (i + 2) == 0):
            return False
    return True

def iil():
    return [int(x) for x in input().split()]

n=int(input())
nums=iil()

def check(x,y):
    if x<0 or y<0 or x>=n or y>=n:
        return 0
    nums[x],nums[y]=nums[y],nums[x]
    ret=-1
    for i in range(n-1):
        if is_prime(nums[i]+nums[i+1]) is False:
            ret=0
            break
    nums[x],nums[y]=nums[y],nums[x]
    return ret

ans=-2
for i in range(n-1):
    if is_prime(nums[i]+nums[i+1]) is False:
        if check(i,i+1) == -1:
            ans=i
        elif check(i+1,i+2) == -1:
            ans=i+1
        elif check(i-1,i) == -1:
            ans=i-1
        break

print(ans+1)
