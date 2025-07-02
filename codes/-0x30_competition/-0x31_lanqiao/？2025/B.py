import os
import sys
import math

n, s, e, d = map(int, input().split())

def cal(p):
  p = (p % n + n) % n
  if p == 0: p += n
  if p <= e: return e - p
  return n - p + e

ans = min(cal(s), cal(s - d), cal(s + d))

print(ans)