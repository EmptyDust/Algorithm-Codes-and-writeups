import queue

n = int(input())
que = queue.Queue()
stk = queue.LifoQueue()
g_pq = queue.PriorityQueue()
l_pq = queue.PriorityQueue()

q=s=l=g=True
op1=op2=0
for i in range(n):
    opt,v = [int(x) for x in input().split()]
    if opt == 1:
        if q:
            que.put(v)
        if s:
            stk.put(v)
        if l:
            l_pq.put((v,v))
        if g:
            g_pq.put((-v,v))
        op1+=1
    else:
        if que.empty() or v != que.get():
            q = False
        if stk.empty() or v != stk.get():
            s = False
        if l_pq.empty() or v != l_pq.get()[1]:
            l = False
        if g_pq.empty() or v != g_pq.get()[1]:
            g = False
        op2+=1
print(f'{op1} {op2}')
print("Yes"if q else"No")
print("Yes"if s else"No")
print("Yes"if g else"No")
print("Yes"if l else"No")