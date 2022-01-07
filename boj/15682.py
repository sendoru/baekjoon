import sys
from decimal import *
input = sys.stdin.readline

def cubic(a, b, c, d, x):
    return a * (x ** 3) + b * (x ** 2) + c * x + d

def determinant(a, b, c):
    return b ** 2 - 4 * a * c

def solve2(a, b, c):
    d = determinant(a, b, c)
    if d > 0:
        return [(-b + pow(d, Decimal("0.5"))) / (2 * a), (-b - pow(d, Decimal("0.5"))) / (2 * a)]
    elif d == 0:
        return [-b / (2 * a)]
    else:
        return []

def solve3(a, b, c, d):
    ret = []
    dm = int(100000000000 * d)

    if d != Decimal(0):
        for i in range(-1000000, 1000001):
            if i != 0 and dm % i == 0 and cubic(a, b, c, d, i) == 0:
                ret.append(Decimal(i))
                break
    else:
        ret.append(Decimal(0))
    
    rootOfQuad = solve2(a, ret[0] * a + b, ret[0] * ret[0] * a + ret[0] * b + c)

    for elem in rootOfQuad:
        if abs(ret[0] - elem) > .99e-9:
            ret.append(elem)
    ret.sort()
    return ret

t = int(input())
for i in range(t):
    a, b, c, d = map(Decimal, input().rstrip().split(' '))
    root = solve3(a, b, c, d)
    for j in root:
        print(j, end = ' ')
    print()

