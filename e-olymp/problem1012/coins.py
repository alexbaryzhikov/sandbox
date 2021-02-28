# Brute force

s1 = input()
s2 = input()

n = int(s1.split(" ")[0])
coins = [int(x) for x in s2.split(" ")]


def sumCoins(nums):
    result = 0
    for i in range(len(nums)):
        result += coins[i] * nums[i]
    return result


def next(nums):
    i = 0
    while (i < len(coins)):
        if nums[i] < 2:
            nums[i] += 1
            return True
        elif (i < len(coins) - 1):
            nums[i] = 0
            i += 1
        else:
            return False


def solve():
    if sum(coins) * 2 < n:
        print(-1)
        return

    nums = [0] * len(coins)
    results = []
    while (next(nums)):
        if (sumCoins(nums) == n):
            results.append(nums.copy())

    if len(results) == 0:
        print(0)
        return

    result = min(results, key=lambda xs: sum(xs))
    print(sum(result))


solve()
