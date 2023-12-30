from math import gcd
from collections import OrderedDict
from random import randint
import sys
input = lambda: sys.stdin.readline().rstrip()

factors = {}

def modpow(a, exp, mod):
    r = 1
    b = a % mod
    while exp > 0:
        if exp % 2 == 1:
            r = r * b % mod
        b = b * b % mod
        exp >>= 1
    return r

def isComposite(n, a, d, s):
    x = modpow(a, d, n)
    if x == 1 or x == n - 1:
        return False
    for r in range(s):
        x = x * x % n
        if x == n - 1:
            return False
    return True

def isPrime(x):
    if x < 2:
        return False
    r = 0
    d = x - 1
    while d % 2 == 0:
        d >>= 1
        r += 1
    for i in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41]:
        if x == i:
            return True
        if isComposite(x, i, d, r):
            return False
    return True

def decompose(n):
    if n == 1:
        return
    if isPrime(n):
        if factors.get(n) == None:
            factors[n] = 1
        else:
            factors[n] += 1
        return
    for mod in [2, 3, 5]:
        if n % mod == 0:
            if factors.get(mod) == None:
                factors[mod] = 1
            else:
                factors[mod] += 1
            decompose(n // mod)
            return
    x, y, c, g = 2, 2, 1, 1
    f = lambda x: (x * x % n + c) % n
    while g == 1:
        x = f(x)
        y = f(f(y))
        g = gcd(abs(x - y), n)
        if g == n:
            x = y = randint(0, n - 3)
            c = randint(1, 10)
            g = 1
    decompose(g)
    decompose(n // g)

n = int(input())
decompose(n)
ans = 1

for k, v, in factors.items():
    ans *= v + 1

print(ans)


