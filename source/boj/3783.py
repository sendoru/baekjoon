import sys
from math import *
from decimal import *
input = sys.stdin.readline

getcontext().prec = 185
t = int(input().rstrip())
for i in range(t):
    n = int(input().rstrip())
    n *= 10 ** 30
    ans = n >> 1
    interval = (n >> 2)
    while True:
        if ans * ans * ans > n:
            ans -= interval
        else:
            if (ans + 1) * (ans + 1) * (ans + 1) > n:
                break
            else:
                ans += interval
        remainder = interval & 1
        interval = remainder + (interval >> 1)
    print(str(ans)[:-10] + '.' + str(ans)[-10:])

