n = int(input())

a = list(map(int,input().split()))

print(len(a)*(max(a)-min(a)))