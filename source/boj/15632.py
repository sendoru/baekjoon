x1, y1, r1 = map(int, input().split())
x2, y2, r2 = map(int, input().split())
x3, y3, r3 = map(int, input().split())
ans = 0
step = 0.005

i = step / 2
while i < 100:
    j = step / 2
    while j < 100:
        if (i - x1) * (i - x1) + (j - y1) * (j - y1) < r1 * r1 \
        or (i - x2) * (i - x2) + (j - y2) * (j - y2) < r2 * r2 \
        or (i - x3) * (i - x3) + (j - y3) * (j - y3) < r3 * r3:
            ans += step * step
        j += step
    i += step

print(ans)