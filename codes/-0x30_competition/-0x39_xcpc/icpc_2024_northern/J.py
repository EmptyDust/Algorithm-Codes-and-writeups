import sys

n, k = map(int, sys.stdin.readline().split())
res = []

for _ in range(2 * k):
    degrees = [0] * (n + 1)
    for _ in range(n - 1):
        u, v = map(int, sys.stdin.readline().split())
        degrees[u] += 1
        degrees[v] += 1
    res.append(sum(d * d for d in degrees[1:])) 

sorted_pairs = sorted(enumerate(res), key=lambda x: (-x[1], x[0]))
selected_indices = {pair[0] for pair in sorted_pairs[:k]}

for idx in range(2 * k):
    if idx in selected_indices:
        print("DSU")
    else:
        print("Uniform")