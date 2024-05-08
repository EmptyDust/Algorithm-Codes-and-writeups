MAXN = int(1e5)
n,m,k = [int(x)for x in input().split()]

m-=1;k-=1
s = [input().strip() for _ in range(n)]
s.sort()
res = []

path = [0]*n
st = [0]*n
def dfs(u):
    if u == n:
        order = [""]*n
        for i in range(n):
            order[i] = s[path[i]]
        #print(order)
        if order[m] == "aye" and order[k] == "AYE":
            res.append(order)
        return
    for i in range(n):
        if not st[i]:
            path[u] = i
            st[i] = True
            dfs(u+1)
            st[i] = False

dfs(0)
print(len(res))
for order in sorted(res):
    print(" ".join(order))

