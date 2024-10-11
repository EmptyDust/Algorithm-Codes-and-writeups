T = int(input())

for _ in range(T):
    s = input()
    
    left1 = [0] * len(s)

    cur = 0
    for i in range(len(s)):
        cur += s[i] == '1'
        left1[i] = cur

    right1 = [0] * len(s)

    cur = 0
    for i in range(len(s)-1,-1,-1):
        cur += s[i] == '1'
        right1[i] = cur

    def check(x):
        print(x)
        l = 0;r = 0
        cnt = 0
        while r < len(s):
            while r < len(s) and cnt < x:
                cnt += s[r] == '0'
                r += 1
            cnt1 = 0
            if l != 0:
                cnt1 += left1[l-1]
            if r < len(s) - 1:
                cnt1 += right1[r+1]
            if cnt1 < x:
                return True
            cnt -= s[l] == '0'
            l += 1
            r = max(l,r)
            print(l,r)
        return False
    
    ans = len(s)
    l = 0;r = ans
    while l<=r:
        mid = l+r>>1
        if check(mid):
            r = mid-1
            ans = mid
        else:
            l = mid+1
    print(ans)