import math
import random
N = int(1.5e5)
M = int(1.5e5)
print(f"{N} {M}")
print(' '.join(str(int(math.sqrt(N))) for i in range(N)))
print(' '.join(str(1) for i in range(M)))
