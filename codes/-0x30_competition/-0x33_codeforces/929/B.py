t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]
    sum = 0
    cnt = [0]*3
    for num in a:
        sum+=num
        cnt[num%3]+=1
    sum %= 3
    if sum == 0:
        print(0)
        continue
    if sum == 1:
        if cnt[1]:
            print(1)
        else:
            print(2)
        continue
    if sum == 2:
        print(1)
        continue