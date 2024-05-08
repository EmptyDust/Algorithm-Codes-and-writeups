import queue
mod = int(1e9+7)
t = int(input())
for __ in range(t):
    n,m,k = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]
    a.sort()
    b.sort()
    pq = queue.PriorityQueue()

    for i in range(n):
        pq.put((a[i]+b[0],(i,0)))

    sum = 0
    for _ in range(k):
        cur = pq.get()
        sum += cur[0] % mod
        sum %= mod
        if cur[1][1] < m-1:
            pq.put((a[cur[1][0]]+b[cur[1][1]+1],(cur[1][0],cur[1][1]+1)))

    print(sum)