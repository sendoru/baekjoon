from decimal import *
getcontext().prec = 200
PI = Decimal("3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196")
def sin(x):
    x = x % (2 * PI)
    if x > PI:
        x -= 2 * PI
    index = Decimal(1)
    prevRet = Decimal(0)
    ret = Decimal(x)
    denominator = Decimal(1)
    numerator = Decimal(x)
    sign = Decimal(1)
    while not -(Decimal(str("0." + "0" * 170 + "1"))) < ret - prevRet < Decimal(str("0." + "0" * 170 + "1")):
        prevRet = ret
        index += 2
        sign *= -1
        numerator *= x * x
        denominator *= index * (index - 1)
        ret += sign * numerator / denominator
    return ret

def cos(x):
    x = x % (2 * PI)
    if x > PI:
        x -= 2 * PI
    index = Decimal(0)
    prevRet = Decimal(0)
    ret = Decimal(1)
    denominator = Decimal(1)
    numerator = Decimal(1)
    sign = Decimal(1)
    while not -(Decimal(str("0." + "0" * 170 + "1"))) < ret - prevRet < Decimal(str("0." + "0" * 170 + "1")):
        prevRet = ret
        index += 2
        sign *= -1
        numerator *= x * x
        denominator *= index * (index - 1)
        ret += sign * numerator / denominator
    return ret

a, b, c = map(Decimal, input().split())
x = c / a
prevX = -1
while not -(Decimal(str("0." + "0" * 170 + "1"))) < x - prevX < Decimal(str("0." + "0" * 170 + "1")):
    prevX = x
    x = x - (a * x + b * sin(x) - c) / (a + b * cos(x))

print(round(x, 6))


