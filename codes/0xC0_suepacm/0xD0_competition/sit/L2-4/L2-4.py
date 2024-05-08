from collections import namedtuple
t = int(input())
for __ in range(t):
    n,m = [int(x) for x in input().split()]
    dsu = [x for x in range(n)]
    def get_root(x):
        dsu[x] = (x if x == dsu[x] else get_root(dsu[x]))
        return dsu[x]
    adj = [[]]*n
    print(adj)
    f = False
    for i in range(m):
        u,v = [int(x) for x in input().split()]
        u-=1
        v-=1
        if f:
            continue
        if get_root(u) == get_root(v):
            ed = v
            ans = []
            ans.append(i+1)
            def dfs(x,pre):
                if x == ed:
                    return True
                for nxt,num in adj[x]:
                    print(x,nxt,num)
                    if pre != nxt and dfs(nxt,x):
                        global ans
                        ans.append(num)
                        return True
                return False
            dfs(u,-1)
            ans.sort()
            for num in ans:
                print(num,end=' ')
            print()
            f = True
            continue
        adj[u].append((v,i+1))
        adj[v].append((u,i+1))
        dsu[get_root(u)]=get_root(v)
    if not f:
        print(-1)