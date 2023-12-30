from math import *
from decimal import *
import sys
getcontext().prec = 40
PI = Decimal("3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196")
ERR = Decimal(str("0." + "0" * 35 + "1"))
input = lambda: sys.stdin.readline().rstrip()

class DecimalComplex:
    def __init__(self, _real, _imag = 0):
        self.real = Decimal(_real)
        self.imag = Decimal(_imag)
    def __equal__(self, other):
        return (self.real == other.real and self.imag == other.imag)
    def __add__(self, other):
        return DecimalComplex(self.real + other.real, self.imag + other.imag)
    def __sub__(self, other):
        return DecimalComplex(self.real - other.real, self.imag - other.imag)
    def __mul__(self, other):
        return DecimalComplex(self.real * other.real - self.imag * other.imag, self.real * other.imag + self.imag * other.real)
    def __truediv__(self, other):
        return DecimalComplex((self.real * other.real + self.imag * other.imag) / (other.real * other.real + other.imag * other.imag), (self.imag * other.real - self.real * other.imag) / (other.real * other.real + other.imag * other.imag))
    def __str__(self):
        if self.imag >= 0:
            return str(self.real) + '+' + str(self.imag) + 'j'
        else:
            return str(self.real) + '-' + str(self.imag * (-1)) + 'j'

def decSin(x):
    x = x % (2 * PI)
    if x > PI:
        x -= 2 * PI
    index = Decimal(1)
    prevRet = Decimal(0)
    ret = Decimal(x)
    denominator = Decimal(1)
    numerator = Decimal(x)
    sign = Decimal(1)
    while not -ERR < ret - prevRet < ERR:
        prevRet = ret
        index += 2
        sign *= -1
        numerator *= x * x
        denominator *= index * (index - 1)
        ret += sign * numerator / denominator
    return ret

def decCos(x):
    x = x % (2 * PI)
    if x > PI:
        x -= 2 * PI
    index = Decimal(0)
    prevRet = Decimal(0)
    ret = Decimal(1)
    denominator = Decimal(1)
    numerator = Decimal(1)
    sign = Decimal(1)
    while not -ERR < ret - prevRet < ERR:
        prevRet = ret
        index += 2
        sign *= -1
        numerator *= x * x
        denominator *= index * (index - 1)
        ret += sign * numerator / denominator
    return ret

def fft(f, w):
    n = len(f)
    if n == 1:
        return

    even = [DecimalComplex(0, 0) for _ in range(n // 2)]
    odd = [DecimalComplex(0, 0) for _ in range(n // 2)]

    for i in range(n):
        if i % 2 == 0:
            even[i // 2] = f[i]
        else:
            odd[i // 2] = f[i]

    fft(even, w * w)
    fft(odd, w * w)

    wp = DecimalComplex(1, 0)
    for i in range(n // 2):
        f[i] = even[i] + wp * odd[i]
        f[i + n // 2] = even[i] - wp * odd[i]
        wp *= w

    del even
    del odd

def multiplyPol(f, g):
    n = 1
    while(n < len(f) or n < len(g)):
        n *= 2
    n *= 2
    while len(f) != n:
        f.append(DecimalComplex(0, 0))
    while len(g) != n:
        g.append(DecimalComplex(0, 0))

    w = DecimalComplex(decCos((2 * PI) / n), decSin((2 * PI) / n))
    fft(f, w)
    fft(g, w)
    h = [DecimalComplex(0, 0) for _ in range(n)]
    for i in range(n):
        h[i] = f[i] * g[i]

    fft(h, DecimalComplex(1, 0) / w)
    ans = 0
    for i in range(n):
        h[i] /= DecimalComplex(n, 0)
        h[i] = int(round(h[i].real))
        ans ^= h[i]
    print(ans)


n, m = map(int, input().split())
f = list(map(DecimalComplex, input().split()))
g = list(map(DecimalComplex, input().split()))

multiplyPol(f, g)