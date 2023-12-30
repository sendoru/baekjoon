import datetime

def main():
    n = int(input())

    if n == 0:
        print(0)
        return

    com = []
    for i in range(n):
        rawComment = input().split()
        curDate = list(map(int, rawComment[0].split("/")))
        curTime = list(map(int, rawComment[1].split(":")))
        curDateTime = datetime.datetime(curDate[0], curDate[1], curDate[2], curTime[0], curTime[1], curTime[2])
        curDiff = int(rawComment[2])
        com.append((curDateTime, curDiff))

    p = []
    pl = []
    for i in range(n):
        curDelta = (com[-1][0] - com[i][0])
        # print(curDelta.total_seconds() / (365 * 24 * 60 * 60))
        p.append(max(pow(0.5, curDelta.total_seconds() / (365 * 24 * 60 * 60)), pow(0.9, n - i - 1)))
        pl.append(p[i] * com[i][1])

    X = sum(pl) / sum(p)
    print(round(X))



if __name__ == "__main__":
    main()