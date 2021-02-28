# Table

s1 = input()
s2 = input()

n = int(s1.split(" ")[0])
coins = [int(x) for x in s2.split(" ")]

INFINITY = float("inf")


def showTable(t, coins):
    print(" " * 12, end="")
    for x in coins:
        print(f"{x:5} ", end="")
    print()

    for i in range(len(t)):
        row = t[i]
        print(f"{i:5} ", end="")
        for x in row:
            print(f"{x:5} ", end="")
        print()


def solve():
    if sum(coins) < n:
        print(-1)
        return

    coins2 = coins * 2
    m = len(coins) * 2

    t = [[INFINITY] * (m + 1) for _ in range(n + 1)]

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            c = coins2[j - 1]
            if c > i:
                t[i][j] = t[i][j - 1]
            elif c == i:
                t[i][j] = 1
            else:
                t[i][j] = min(t[i][j - 1], t[i - c][j - 1] + 1)

    showTable(t, coins2)

    if t[-1][-1] == INFINITY:
        print(0)
    else:
        print(t[-1][-1])


solve()
