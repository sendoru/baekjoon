# 그냥 자릿수가 소수여야 되네
mods = tuple(int("1" * i) for i in (2, 3, 5, 7, 11, 13, 17))
n = int(input())
ans = 0
# 약수 1개
for i in range(len(mods)):
    ans += n // mods[i]

# 약수 2개
for i in range(len(mods)):
    for j in range(i + 1, len(mods)):
        ans -= n // (mods[i] * mods[j])

# 약수 3개
for i in range(len(mods)):
    for j in range(i + 1, len(mods)):
        for k in range(j + 1, len(mods)):
            ans += n // (mods[i] * mods[j] * mods[k])

# 약수 4개
for i in range(len(mods) - 1):
    for j in range(i + 1, len(mods) - 1):
        for k in range(j + 1, len(mods) - 1):
            for l in range(k + 1, len(mods) - 1):
                ans -= n // (mods[i] * mods[j] * mods[k] * mods[l])

# 이 이상은 없음
print(ans)