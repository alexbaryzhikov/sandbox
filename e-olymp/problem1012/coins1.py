# Graph search

s1 = input()
s2 = input()

n = int(s1.split(" ")[0])
coins = [int(x) for x in s2.split(" ")]


def sumCoins(nums):
    result = 0
    for i in range(len(nums)):
        result += coins[i] * nums[i]
    return result


def neighbors(nums, start, visited, coins):
    result = []
    v = sumCoins(nums)
    for i in range(start, len(nums)):
        if nums[i] < 2 and v + coins[i] <= n:
            copy = list(nums)
            copy[i] += 1
            neighbor = tuple(copy)
            if neighbor not in visited:
                result.append((neighbor, i))
    return result


def solve():
    if sum(coins) * 2 < n:
        print(-1)
        return

    sortedCoins = sorted(coins)
    results = []
    visited = set()
    queue = []
    queue.append(((0,) * len(coins), 0))

    while (len(queue) > 0):
        nums, start = queue.pop(0)
        for neighbor, s in neighbors(nums, start, visited, sortedCoins):
            visited.add(neighbor)
            if sumCoins(neighbor) == n:
                results.append(neighbor)
            else:
                queue.append((neighbor, s))

    if len(results) == 0:
        print(0)
        return

    result = min(results, key=lambda xs: sum(xs))
    print(sum(result))


solve()
