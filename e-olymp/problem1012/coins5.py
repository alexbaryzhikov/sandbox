# Recursion

s1 = input()
s2 = input()

n = int(s1.split(" ")[0])
coins = [int(x) for x in s2.split(" ")]


def take(coins, m):
    if m == 0:
        return [[]]
    if m == 1:
        return [[coins[x]] for x in range(len(coins))]
    k = (len(coins) - 1) * 2
    result = []
    if m - 2 <= k:
        result += [[coins[0], coins[0]] + xs for xs in take(coins[1:], m - 2)]
        if m - 1 <= k:
            result += [[coins[0]] + xs for xs in take(coins[1:], m - 1)]
            if m <= k:
                result += take(coins[1:], m)
    return result


def solve():
    if sum(coins) * 2 < n:
        print(-1)
        return

    for i in range(1, len(coins) * 2 + 1):
        for xs in take(coins, i):
            if sum(xs) == n:
                print(len(xs))
                return
    print(0)


solve()
