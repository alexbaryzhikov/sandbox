# Recursion (optimized)

s1 = input()
s2 = input()

n = int(s1.split(" ")[0])
coins = [int(x) for x in s2.split(" ")]


def explore(m, nums=[0] * len(coins), pos=0, partSum=0):
    done = True

    if m == 0:
        if partSum == n:
            return sum(nums)
        if partSum < n:
            done = False

    elif m == 1:
        for i in range(pos, len(coins)):
            if partSum + coins[i] == n:
                nums[i] = 1
                return sum(nums)
            if partSum + coins[i] < n:
                done = False

    else:
        restNum = (len(coins) - pos - 1) * 2
        if m - 2 <= restNum:
            nums[pos] = 2
            result = explore(m - 2, nums, pos + 1, partSum + coins[pos] * 2)
            if result > 0:
                return result
            if result == 0:
                done = False
            if m - 1 <= restNum:
                nums[pos] = 1
                result = explore(m - 1, nums, pos + 1, partSum + coins[pos])
                if result > 0:
                    return result
                if result == 0:
                    done = False
                nums[pos] = 0
                if m <= restNum:
                    result = explore(m, nums, pos + 1, partSum)
                    if result > 0:
                        return result
                    if result == 0:
                        done = False
            else:
                nums[pos] = 0

    return -1 if done else 0


def solve():
    if sum(coins) * 2 < n:
        print(-1)
        return

    if sum(coins) * 2 == n:
        print(len(coins) * 2)
        return

    if n % 2 != 0 and all(c % 2 == 0 for c in coins):
        print(0)
        return

    for i in range(1, len(coins) * 2 + 1):
        result = explore(i)
        if result > 0:
            print(result)
            return
        if result == -1:
            break

    print(0)


solve()
