from queue import Queue
import sys
input  = sys.stdin.readline
n, m = map(int, input().rstrip().split())
# expressions[a] = [min, [b1, b2, ...], [c1, c2, ...]] -> 재료 a를 만드는 데 bi만큼의 비용 + ci에 있는 재료들이 필요하고, 이때 최소 비용은 min
# 여기서 c는 dict의 형태로 주어지며, c[d] = e이면 재료 d가 e개만큼 필요하다는 뜻
exp = dict()
cost = dict()
minCost = dict()
pre = dict()
suc = dict()
q = Queue()

for i in range(n):
    k, v = input().rstrip().split()
    v = int(v)
    exp[k] = [dict()]
    cost[k] = [v]
    minCost[k] = v
    q.put(k)

for i in range(m):
    rawInput = input().rstrip()
    left, right = rawInput.split('=')
    right = right.split('+')
    rightDict = dict()
    for j in range(len(right)):
        if rightDict.get(right[j][1:]) == None:
            rightDict[right[j][1:]] = int(right[j][0])
        else:
            rightDict[right[j][1:]] += int(right[j][0])
    if not left in rightDict:
        if (not left in exp):
            exp[left] = [rightDict]
            cost[left] = [0]
            minCost[left] = -1
        else:
            exp[left].append(rightDict)
            cost[left].append(0)

for k, v in exp.items():
    pre[k] = [set(k for k in v[i]) for i in range(len(v))]
    suc[k] = {_ for _ in exp if _ != k}

if not "LOVE" in exp:
    print(-1)

else:
    while not q.empty():
        curIng = q.get()
        for elem in suc[curIng]:
            for i in range(len(exp[elem])):
                if curIng in pre[elem][i]:
                    cost[elem][i] += minCost[curIng] * exp[elem][i][curIng]
                    pre[elem][i].remove(curIng)
                if len(pre[elem][i]) == 0:
                    if minCost[elem] == -1:
                        minCost[elem] = cost[elem][i]
                        q.put(elem)
                    elif cost[elem][i] < minCost[elem]:
                        for k in suc[elem]:
                            for j in range(len(exp[k])):
                                if exp[k][j].get(elem) != None and not elem in pre[k][j]:
                                    cost[k][j] -= minCost[elem] * exp[k][j][elem]
                                    pre[k][j].add(elem)
                        minCost[elem] = cost[elem][i]
                        q.put(elem)

    print(min(1000000001, minCost["LOVE"]))

