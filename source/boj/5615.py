from math import gcd
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

n = int(input())
cnt = 0
for i in range(n):
    s = int(input()) * 2 + 1
    if isPrime(s):
        cnt += 1

print(cnt)