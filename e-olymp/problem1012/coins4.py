# Combinations

from itertools import combinations

s1 = input()
s2 = input()

n = int(s1.split(" ")[0])
coins = [int(x) for x in s2.split(" ")]


def solve():
    if sum(coins) * 2 < n:
        print(-1)
        return

    coins2 = coins * 2

    for i in range(1, len(coins2) + 1):
        for c in combinations(coins2, i):
            if sum(c) == n:
                print(len(c))
                return
    print(0)

solve()