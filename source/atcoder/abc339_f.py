from bisect import bisect_left, bisect_right

n = int(input())
a = []
a_lens = []

ans = 0
a.sort()

for i in range(n):
    a_lens.append(len(str(a[i])))

for i in range(n):
    for j in range(i + 1, n):
        if a_lens[i] + a_lens[j] < a_lens[-1] + 5:
            continue
        cur = a[i] * a[j]
        ans += 2 * (bisect_right(a, cur) - bisect_left(a, cur))

for i in range(n):
    if a_lens[i] + a_lens[i] < a_lens[-1] + 5:
        continue
    cur = a[i] * a[i]
    if cur <= a[-1]:
        ans += (bisect_right(a, cur) - bisect_left(a, cur))

print(ans)