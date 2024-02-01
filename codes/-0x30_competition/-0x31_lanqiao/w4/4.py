import os
import sys

n,q=[int(x) for x in input().split()]
nums=[int(x) for x in input().split()]
ans=["NO","YES"]

for x in range(q):
    l,r=[int(x) for x in input().split()]
    if r-l>100:
        print("YES")
    else:
        pre=-1000
        f=0
        for num in sorted(nums[l-1:r]):
            if abs(num-pre)<=365:
                f=1
                break
            pre=num
        print(ans[f])