import itertools as it


def getEqualPartsBf(weights: list[int], offset: int):
    weightsSorted = sorted(weights)
    for i in range(len(weightsSorted)):
        for left in it.combinations(weightsSorted, i):
            leftSum = sum(left) + offset
            leftSet = set(left)
            rest = tuple(x for x in weightsSorted if x not in leftSet)
            for j in range(len(rest) + 1):
                for right in it.combinations(rest, j):
                    if (sum(right) == leftSum):
                        return left, right
    return None


def printResult(parts):
    if parts == None:
        print(-1)
    else:
        print(" ".join(str(x) for x in parts[0]) or 0)
        print(" ".join(str(x) for x in parts[1]) or 0)
    print()


printResult(getEqualPartsBf([3, 5], 5))
printResult(getEqualPartsBf([6, 3, 4], 5))
printResult(getEqualPartsBf([2], 5))
