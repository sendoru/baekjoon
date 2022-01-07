n = int(input())
sums = [0 for _ in range(36)]
diffs = [0 for _ in range(36)]
for i in range(n):
    num = input()
    for j in range(len(num)):
        if num[j] <= '9':
            sums[int(num[j])] += int(num[j]) * (36 ** (len(num) - j - 1))
            diffs[int(num[j])] += (35 - int(num[j])) * (36 ** (len(num) - j - 1))
        else:
            sums[ord(num[j]) - ord('A') + 10] += (ord(num[j]) - ord('A') + 10) * (36 ** (len(num) - j - 1))
            diffs[ord(num[j]) - ord('A') + 10] += (35 - (ord(num[j]) - ord('A') + 10)) * (36 ** (len(num) - j - 1))

diffs.sort(reverse = True)

k = int(input())
total = sum(sums) + sum(diffs[:k])
ans = []
while(total != 0):
    ans.append(total % 36)
    total //= 36

if len(ans) == 0:
    print(0)

for i in range(len(ans) - 1, -1, -1):
    if ans[i] <= 9:
        print(ans[i], end = '')
    else:
        print(chr(ans[i] - 10 + ord('A')), end = '')